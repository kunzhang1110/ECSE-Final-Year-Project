#include <math.h>
#define ADCLOOP_EXEC_TIME 0.0001429    //execution time of loops with analogueRead
#define LOOP_EXEC_TIME 0.00008333      //execution time of loop without analogueRead
#define REF_FREQUENCY 300
#define DEAD_TIME 3                    //dead time in micro seconds
#define SINE_TABLE_MAX 20
#define FEEDBACK_GAIN 0
#define PROP_GAIN 1
/******************************************************************************************************/
/*    This code is to use preset reference signal freqeucies and generate PWM in close loop           */
/*    Version 7, based on SIMULINK code  sim_Motor_2kW_closedloop_v8_delay                            */
/*    All data are int type                                                                           */
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
//Frequencies of reference
int REF_FREQ= 300;                  //reference AC frequency

//initialize variables
int ref_a= 0;
int ref_b= 0;
int ref_c= 0;
int ctrl_a= 0;
int ctrl_b= 0;
int ctrl_c= 0;
int sem_1= 0;                      //semaphore for dead time delay for leg 1
int sem_2= 0;                      //semaphore for dead time delay for leg 2
int sem_3= 0;                      //semaphore for dead time delay for leg 3
int counter= 0;
int counter_max= 1000;
int counter_dum= 0;
int fb_a= 0;
int fb_b= 0;
int fb_c= 0;
int i= 0;
int j= 6;
int down_flag= 0;                      //flag for downward counting
int sin_table[21]={500, 655, 794, 905, 976, 1000,976, 905, 794, 655, 500,355, 206, 95, 24, 0, 24, 95, 206, 345, 500};

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
  ADCSRA=  0x84;                               //set ADC prescalar to 16; enable ADC conversion
//  TCCR0B= _BV(CS00)|_BV(CS01);                 //default Timer0 prescaler of 64
  counter_max= 1000;//(1/REF_FREQUENCY*(SINE_TABLE_MAX+1)-ADCLOOP_EXEC_TIME)/LOOP_EXEC_TIME;      //counter max is calculated by reference_frequency
//  for(i=0;i<=SINE_TABLE_MAX;i++){                                                          //rescale sine table according to counter_max
//         sin_table[i]= sin_table[i]*counter_max/1000;
//  }    
/******************************************************************************************************/
  while(1){
       if(counter==counter_max||counter==0){               //if counter reaches maximum, take new values
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
             ref_a= sin_table[i];                          //set ref_phase to a scale of 0 to COUNT_MAX
             ref_b= sin_table[j];            
             ref_c= (-ref_a-ref_b)+3/2*counter_max;        //obtain ref_c from ref_a and ref_b
             fb_a=analogRead(fdb_a_Pin);
             fb_b=analogRead(fdb_b_Pin);
             fb_c= -fb_a-fb_b;
             ctrl_a= (ref_a-fb_a*FEEDBACK_GAIN)*PROP_GAIN;  
             ctrl_b= (ref_b-fb_b*FEEDBACK_GAIN)*PROP_GAIN;
             ctrl_c= (ref_c-fb_c*FEEDBACK_GAIN)*PROP_GAIN; 
             sem_1= 0;                                    //reset semaphores
             sem_2= 0;
             sem_3= 0;             
       }
       if (counter==0) {    
             down_flag= 0;            //flag count up
       }else if (counter==counter_max){
             down_flag= 1;           //flag count down
       }
/*Count up*********************************************************/
        if(down_flag==0){
               if(counter<ctrl_a){
                      PORTD &= ~0x04;      PORTD |= 0x08;
               }else if(sem_1==0) {
                      PORTD &= ~0x04;      PORTD &= ~0x08;
                      delayMicroseconds(DEAD_TIME);
                      PORTD |= 0x04;       PORTD &= ~0x08; 
                      sem_1= 1;  
               }else{
                      PORTD |= 0x04;       PORTD &= ~0x08;         
               }
    
              //leg 2
               if(counter<ctrl_b){
                      PORTD &= ~0x10;      PORTD |= 0x20;
               }else if(sem_2==0) {
                      PORTD &= ~0x10;      PORTD &= ~0x20;
                      delayMicroseconds(DEAD_TIME);
                      PORTD |= 0x10;       PORTD &= ~0x20; 
                      sem_2= 1;  
               }else{
                      PORTD |= 0x10;       PORTD &= ~0x20;         
               } 
     
              //leg 3
             if(counter<ctrl_c){
                    PORTD &= ~0x40;      PORTD |= 0x80;
             }else if(sem_3==0) {
                    PORTD &= ~0x40;      PORTD &= ~0x80;
                    delayMicroseconds(DEAD_TIME);
                    PORTD |= 0x40;       PORTD &= ~0x80; 
                    sem_3= 1;  
             }else{
                    PORTD |= 0x40;       PORTD &= ~0x80;         
             }
             counter= counter+100;  
      }  
/*Count down*********************************************************/ 
        else{
               if(counter>ctrl_a){
                      PORTD |= 0x04;       PORTD &= ~0x08;              
               }else if(sem_1==0) {
                      PORTD &= ~0x04;      PORTD &= ~0x08;
                      delayMicroseconds(DEAD_TIME);
                      PORTD &= ~0x04;      PORTD |= 0x08;    
                      sem_1= 1;  
               }else{
                      PORTD &= ~0x04;      PORTD |= 0x08;    
               }
    
            //leg 2
               if(counter>ctrl_b){
                      PORTD |= 0x10;       PORTD &= ~0x20;  
               }else if(sem_2==0) {
                      PORTD &= ~0x10;      PORTD &= ~0x20;
                      delayMicroseconds(DEAD_TIME);
                      PORTD &= ~0x10;      PORTD |= 0x20; 
                      sem_2= 1;  
               }else{
                      PORTD &= ~0x10;      PORTD |= 0x20;      
               } 
     
        //leg 3
             if(counter<ctrl_c){
                    PORTD |= 0x40;       PORTD &= ~0x80;  
             }else if(sem_3==0) {
                    PORTD &= ~0x40;      PORTD &= ~0x80;
                    delayMicroseconds(DEAD_TIME);
                    PORTD &= ~0x40;      PORTD |= 0x80;    
                    sem_3= 1;  
             }else{
                    PORTD &= ~0x40;      PORTD |= 0x80;       
             }
             counter= counter-100;          
          }             
}     
      
      
      
      
      
      
      


}

/*****************************************************************************************************/
void loop() { 
}   

