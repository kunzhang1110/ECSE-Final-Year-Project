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
//Frequencies of reference signals
int REF_FREQ= 300;                  //reference AC frequency

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
int COUNTER_MAX= 10;
int DEAD_TIME= 1;
int SINE_TABLE_MAX= 20;
double sin_table[21]={5.00, 6.55, 7.94, 9.05, 9.76, 10.00,9.76, 9.05, 7.94, 6.55, 5.00,3.45, 2.06, 0.95, 0.24, 0.00, 0.245, 0.95, 2.06, 3.45, 5.00};
int i= 0;
int j= 6;
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
  cli(); //disable interrupts  
}  


/*****************************************************************************************************/
void loop() {   
   if(counter==COUNTER_MAX){                                                  //if counter reaches maximum, take new values
             if(i==SINE_TABLE_MAX){
               i= 0;
             }else{
               i= i+1;
             } 
             if(j==SINE_TABLE_MAX){
               j= 0;
             }else{
               j= j+1;
             }            
             ref_a_sample= sin_table[i];                                     //set ref_phase to a scale of 0 to COUNT_MAX
             ref_b_sample= sin_table[j];
             ref_c_sample= (-ref_a_sample-ref_b_sample)+15;
             counter= 0;             //reset counter
   }

   if(counter<DEAD_TIME){                                                   //initially, pwm 1->0, delay for 5 ticks (at the rate of Timer2)   
             PORTD &= ~0x4;       PORTD &= ~0x8;              
             PORTD &= ~0x10;      PORTD &= ~0x20;
             PORTD &= ~0x40;      PORTD &= ~0x80;
  //           delayMicroseconds(1);                                          //balance computation time
   }else{
       //leg 1
       if(counter<ref_a_sample){
              PORTD &= ~0x04;      PORTD |= 0x08;
       }else if(counter<ref_a_sample+DEAD_TIME){
              PORTD &= ~0x04;      PORTD &= ~0x08;
       }else{
              PORTD |= 0x04;       PORTD &= ~0x08;   
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
}   


