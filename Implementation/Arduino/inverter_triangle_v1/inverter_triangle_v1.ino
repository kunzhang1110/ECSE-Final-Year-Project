#include <math.h>
/******************************************************************************************************/
/*    This code is to use triangular wave and generate PWM in open loop without delay                 */
/*    Version 1, based on SIMULINK code                                                               */
/*                                                                                                    */
/******************************************************************************************************/

//PWM pin numbers
int pwm_1_Pin= 2;               
int pwm_2_Pin= 3;                 
int pwm_3_Pin= 4;                   
int pwm_4_Pin= 5;                   
int pwm_5_Pin= 6;                  
int pwm_6_Pin= 7;                  

//Analogue pin number
int fdb_a_Pin= A0;                  //select A0,A1 for feedback signals
int fdb_b_Pin= A1;

//Frequencies of reference signals
int REF_FREQ= 300;                  //reference AC frequency
int REF_AMP= 1;
int AMP_MOD= 0.9;
int FREQ_MOD= 100;
int TRI_AMP= 0;
int TRI_FREQ= 0;
int TRI_PER= 0;

//initialize variables
double ref_phase_a= 0;
double ref_phase_b= 0;
double ref_phase_c= 0;
double tri_wav= 0;
double current_time= 0;
double time= 0;

double sin_table[21]={5.00, 6.55, 7.94, 9.05, 9.76, 10.00,9.76, 9.05, 7.94, 6.55, 5.00,3.45, 2.06, 0.95, 0.24, 0.00, 0.245, 0.95, 2.06, 3.45, 5.00};

/******************************************************************************************************/
void setup(){
  //declare outputs
  pinMode(pwm_1_Pin, OUTPUT);
  pinMode(pwm_2_Pin, OUTPUT);  
  pinMode(pwm_3_Pin, OUTPUT);  
  pinMode(pwm_4_Pin, OUTPUT);  
  pinMode(pwm_5_Pin, OUTPUT);  
  pinMode(pwm_6_Pin, OUTPUT);
  //declare inputs
  pinMode(fdb_a_Pin, INPUT);
  pinMode(fdb_b_Pin, INPUT);
  TRI_AMP= REF_AMP/AMP_MOD;
  TRI_FREQ= FREQ_MOD*REF_FREQ;
  TRI_PER= 1/TRI_FREQ;    
  cli(); //disable interrupts  
}  


/*****************************************************************************************************/
void loop() {
   current_time=time/10000;
   ref_phase_a= REF_AMP*sin(2*M_PI*REF_FREQ*current_time);
   ref_phase_b= REF_AMP*sin(2*M_PI*REF_FREQ*current_time+2*M_PI/3);   
   ref_phase_c= -ref_phase_a-ref_phase_b;
   tri_wav= (2*TRI_AMP/(TRI_PER/2))*abs(fmod(current_time,TRI_PER)-TRI_PER/2)-TRI_AMP; 
  
   //leg 1
   if(ref_phase_a>tri_wav){
              PORTD &= ~0x04;      PORTD |= 0x08;
   }
   else{
              PORTD |= 0x04;       PORTD &= ~0x08;   
   }
   
    //leg 2
    if(ref_phase_b>tri_wav){
              PORTD &= ~0x10;      PORTD |= 0x20;
     }
     else{
              PORTD |= 0x10;       PORTD &= ~0x20;      
     }
 
    //leg 3
     if(ref_phase_c>tri_wav){
              PORTD &= ~0x40;     PORTD |= 0x80; 
     }
     else{
              PORTD |= 0x40;      PORTD &= ~0x80;   
     }  
     time= time+10;
}


