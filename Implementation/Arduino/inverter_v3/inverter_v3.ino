#include <math.h>
/******************************************************************************************************/
/*    This code is to use preset reference signal freqeucies and generate PWM in open loop            */
/*    Version 2, based on SIMULINK code                                                               */
/*                                                                                                    */
/******************************************************************************************************/

//PWM pin numbers
int pwm_1_Pin= 2;                   //OC0A, Timer 0
int pwm_2_Pin= 3;                   //OC0B, Timer 0
int pwm_3_Pin= 4;                   //0C1A, Timer 1
int pwm_4_Pin= 5;                   //OC1B, Timer 1
int pwm_5_Pin= 6;                   //OC2A, Timer 2
int pwm_6_Pin= 7;                   //OC2B, Timer 2

//Analogue pin number
int fdb_a_Pin= A0;                  //select A0,A1 for feedback signals
int fdb_b_Pin= A1;
int ref_a_Pin= A2;                  //select A2,A3 for reference signals
int ref_b_Pin= A3;
int test_Pin= A4;
//Frequencies of reference signals
int REF_FREQ= 300;                  //reference AC frequency
int REF_AMP= 1;                     //refrence AC amplitude  

//initialize variables
int ref_a_sample= 0;
int ref_b_sample= 0;
int ref_c_sample= 0;
double ref_phase_a= 0;
double ref_phase_b= 0;
double ref_phase_c= 0;
int current_time= 0;
int counter= 0;

//define constants
int COUNTER_MAX= 20;
int DEAD_TIME= 1;

double sin_table[20]={0,0.325,0.614,0.837,0.969,0.997,0.916,0.736,0.476,0.165,-0.165,-0.476,-0.736, -0.916, -0.999, -0.969, -0.837, -0.614, -0.325,0};
int i= 0;
/******************************************************************************************************/
void setup(){
  //declare outputs
  pinMode(pwm_1_Pin, OUTPUT);
  pinMode(pwm_2_Pin, OUTPUT);  
  pinMode(pwm_3_Pin, OUTPUT);  
  pinMode(pwm_4_Pin, OUTPUT);  
  pinMode(pwm_5_Pin, OUTPUT);  
  pinMode(pwm_6_Pin, OUTPUT);
  pinMode(test_Pin,OUTPUT);  
  //declare inputs
  pinMode(ref_a_Pin, INPUT);
  pinMode(ref_b_Pin, INPUT);
  pinMode(fdb_a_Pin, INPUT);
  pinMode(fdb_b_Pin, INPUT);  
//  Serial.begin(9600);        // initialize serial communications at 9600 bps:
}  


/*****************************************************************************************************/
void loop() {   
   if(counter==COUNTER_MAX){                                                             //if counter reaches maximum, take new values
//             current_time= micros();
//             ref_phase_a= REF_AMP*sin(2*M_PI*REF_FREQ*current_time);
//             ref_phase_b= REF_AMP*sin(2*M_PI*REF_FREQ*current_time+2*M_PI/3);

             ref_phase_a= REF_AMP*sin_table[i];
             ref_phase_b= REF_AMP*sin_table[i];
             ref_phase_c= -ref_phase_a-ref_phase_b;
             ref_a_sample= int((ref_phase_a+REF_AMP)*COUNTER_MAX/(2*REF_AMP));           //set ref_phase to a scale of 0 to COUNT_MAX
             ref_b_sample= int((ref_phase_b+REF_AMP)*COUNTER_MAX/(2*REF_AMP));
             ref_c_sample= int((ref_phase_c+REF_AMP)*COUNTER_MAX/(2*REF_AMP));
             counter= 0;             //reset counter
             if(i==19){
               i= 0;
             }else{
               i= i+1;
             } 
   }

   if(counter<DEAD_TIME){                                                                //initially, pwm 1->0, delay for 5 ticks (at the rate of Timer2)   
                PORTD &= ~0x4;       PORTD &= ~0x8;              
                PORTD &= ~0x10;      PORTD &= ~0x20;
                PORTD &= ~0x40;      PORTD &= ~0x80;
   }else{
       //leg 1
       if(counter<ref_a_sample){
                 PORTD &= ~0x4;      PORTD |= 0x8;
       }else if(counter<ref_a_sample+DEAD_TIME){
                 PORTD &= ~0x4;      PORTD &= ~0x8;
       }else{
                 PORTD |= 0x4;       PORTD &= ~0x8;   
       }
   
    //leg 2
       if(counter<ref_b_sample){
                 PORTD &= ~0x10;      PORTD |= 0x20;
       }else if(counter<ref_b_sample+DEAD_TIME){
                 PORTD &= ~0x10;      PORTD &= ~0x20;
       }else{
                 PORTD |= 0x10;       PORTD &= ~0x20;      
       }
 
    //leg 3
       if(counter<ref_c_sample){
                PORTD &= ~0x40;     PORTD |= 0x80; 
       }else if(counter<ref_c_sample+DEAD_TIME){
                PORTD &= ~0x40;     PORTD &= ~0x80;
       }else{
                PORTD |= 0x40;      PORTD &= ~0x80;   
       }  
   }
   counter = counter+1;       //counter increments
//   analogWrite(test_Pin, counter);
}   
   

   
   
   
   
   
   
   
   
   
   



