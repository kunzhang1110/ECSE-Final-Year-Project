#include <math.h>
/******************************************************************************************************/
/*    This code is to use preset reference signal freqeucies and generate PWM in open loop            */
/*    Version 5, based on SIMULINK code                                                               */
/*                                                                                                    */
/******************************************************************************************************/

//PWM pin numbers
int pwm_1_Pin= 8;                   
int pwm_2_Pin= 3;                   
int pwm_3_Pin= 4;                  
int pwm_4_Pin= 5;                   
int pwm_5_Pin= 6;                   
int pwm_6_Pin= 7;                   

//Analogue pin number
int fdb_a_Pin= A0;                  //select A0,A1 for feedback signals
int fdb_b_Pin= A1;
//Frequencies of reference
int REF_FREQ= 300;                  //reference AC frequency

//initialize variables
double ref_a= 0;
double ref_b= 0;
double ref_c= 0;
int counter= 0;
double fb_a= 0;
double fb_b= 0;

//define constants
int counter_max= 10;

int sem_1= 0;
int sem_2= 0;
int sem_3= 0;
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
  ADCSRA=  0x84;                              //set ADC prescalar to 16; enable ADC conversion
  while(1){
      if(counter==counter_max){                                                  //if counter reaches maximum, take new values
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
             ref_a= sin_table[i];                                     //set ref_phase to a scale of 0 to COUNT_MAX
             ref_b= sin_table[j];
             ref_c= (-ref_a-ref_b)+15;
             counter= 0;             //reset counter
             sem_1= 0;
             sem_2= 0;
             sem_3= 0;
             fb_a=analogRead(fdb_a_Pin);
             fb_b=analogRead(fdb_b_Pin);
   }

   if(counter==0){                                                   //initially, pwm 1->0, delay for 5 ticks (at the rate of Timer2)   
//             PORTD &= ~0x4;       PORTD &= ~0x8;              
//             PORTD &= ~0x10;      PORTD &= ~0x20;
//             PORTD &= ~0x40;      PORTD &= ~0x80;
      delayMicroseconds(4);
               PORTB= 0;
               PORTD= 0;
//             delayMicroseconds(1);                                          //balance computation time
   }else{
       //leg 1
       if(counter<ref_a){
              PORTB &= ~0x01;      PORTD |= 0x08;
       }else if(sem_1==0) {
              PORTB &= ~0x01;      PORTD &= ~0x08;
              delayMicroseconds(4);
              PORTB |= 0x01;       PORTD &= ~0x08; 
              sem_1= 1;  
       }else{
              PORTB |= 0x01;       PORTD &= ~0x08;         
       } 
   
    //leg 2
       if(counter<ref_b){
              PORTD &= ~0x10;      PORTD |= 0x20;
       }else if(counter<ref_b+DEAD_TIME){
              PORTD &= ~0x10;      PORTD &= ~0x20;
       }else{
              PORTD |= 0x10;       PORTD &= ~0x20;      
       }
 
    //leg 3
       if(counter<ref_c){
              PORTD &= ~0x40;     PORTD |= 0x80; 
       }else if(counter<ref_c+DEAD_TIME){
              PORTD &= ~0x40;     PORTD &= ~0x80;
       }else{
              PORTD |= 0x40;      PORTD &= ~0x80;   
       }  
   }
   counter= counter+1;       //counter increments
  }
}  


/*****************************************************************************************************/
void loop() {    
}   
//Each while loop: 11.9KHz
