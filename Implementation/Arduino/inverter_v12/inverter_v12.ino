#include <math.h>
/******************************************************************************************************/
/*    This code is to use preset reference signal freqeucies and generate PWM in open loop            */
/*    Version 12, based on SIMULINK code                                                               */
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
int fb_c= 0;

//define constants
int counter_max= 1023;
int DEAD_TIME= 1;
int SINE_TABLE_MAX= 512;
int FEEDBACK_GAIN= 0;
int PROP_GAIN= 1;
double sin_table[512]={512,518,524,530,537,543,549,555,562,568,574,580,587,593,599,605,611,617,624,630,636,642,648,654,660,666,672,678,684,690,696,701,707,713,719,725,730,736,741,747,753,758,764,769,774,780,785,790,796,801,806,811,816,821,826,831,836,841,846,850,855,860,864,869,873,878,882,886,890,895,899,903,907,911,915,919,922,926,930,933,937,940,944,947,950,953,957,960,963,966,968,971,974,977,979,982,984,986,989,991,993,995,997,999,1001,1003,1004,1006,1008,1009,1011,1012,1013,1014,1015,1017,1017,1018,1019,1020,1021,1021,1022,1022,1022,1023,1023,1023,1023,1023,1023,1023,1022,1022,1022,1021,1021,1020,1019,1018,1017,1017,1015,1014,1013,1012,1011,1009,1008,1006,1004,1003,1001,999,997,995,993,991,989,986,984,982,979,977,974,971,968,966,963,960,957,953,950,947,944,940,937,933,930,926,922,919,915,911,907,903,899,895,890,886,882,878,873,869,864,860,855,850,846,841,836,831,826,821,816,811,806,801,796,790,785,780,774,769,764,758,753,747,741,736,730,725,719,713,707,701,696,690,684,678,672,666,660,654,648,642,636,630,624,617,611,605,599,593,587,580,574,568,562,555,549,543,537,530,524,518,512,505,499,493,486,480,474,468,461,455,449,443,436,430,424,418,412,406,399,393,387,381,375,369,363,357,351,345,339,333,327,322,316,310,304,298,293,287,282,276,270,265,259,254,249,243,238,233,227,222,217,212,207,202,197,192,187,182,177,173,168,163,159,154,150,145,141,137,133,128,124,120,116,112,108,104,101,97,93,90,86,83,79,76,73,70,66,63,60,57,55,52,49,46,44,41,39,37,34,32,30,28,26,24,22,20,19,17,15,14,12,11,10,9,8,6,6,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,6,6,8,9,10,11,12,14,15,17,19,20,22,24,26,28,30,32,34,37,39,41,44,46,49,52,55,57,60,63,66,70,73,76,79,83,86,90,93,97,101,104,108,112,116,120,124,128,133,137,141,145,150,154,159,163,168,173,177,182,187,192,197,202,207,212,217,222,227,233,238,243,249,254,259,265,270,276,282,287,293,298,304,310,316,322,327,333,339,345,351,357,363,369,375,381,387,393,399,406,412,418,424,430,436,443,449,455,461,468,474,480,486,493,499,505};
int i= 0;
int j= 13;
int n= 8;
/******************************************************************************************************/


void setup(){
  //declare outputs
  pinMode(pwm_1_Pin, OUTPUT);
  pinMode(pwm_2_Pin, OUTPUT);  
  pinMode(pwm_3_Pin, OUTPUT);  
  pinMode(pwm_4_Pin, OUTPUT);  
  pinMode(pwm_5_Pin, OUTPUT);  
  pinMode(pwm_6_Pin, OUTPUT);
  pinMode(13, OUTPUT);
  //declare inputs
  pinMode(fdb_a_Pin, INPUT);
  pinMode(fdb_b_Pin, INPUT);    
  ADCSRA=  0x84;                              //set ADC prescalar to 16; enable ADC conversion
  while(1){
      if(counter==counter_max){                                                  //if counter reaches maximum, take new values
             if(i==SINE_TABLE_MAX){
               i= 0;
             }else{
               i= i+n;
             } 
             if(j==SINE_TABLE_MAX){
               j= 0;
             }else{
               j= j+n;
             }            
             ref_a= sin_table[i];                                     //set ref_phase to a scale of 0 to COUNT_MAX
         ref_b= sin_table[j];
             ref_c= (-ref_a-ref_b)+(counter_max)*3/2;
//                          fb_a=analogRead(fdb_a_Pin);    //feedback ranging from 0-1023
//             fb_b=analogRead(fdb_b_Pin);
//    fb_c= -fb_a-fb_b;  
//                ref_a= (ref_a-fb_a*FEEDBACK_GAIN)*PROP_GAIN;  
//                
//    ref_b= (ref_b-fb_b*FEEDBACK_GAIN)*PROP_GAIN;
//    ref_c= (ref_c-fb_c*FEEDBACK_GAIN)*PROP_GAIN;
             counter= 0;             //reset counter

 }

   if(counter<DEAD_TIME){                                                   //initially, pwm 1->0, delay for 5 ticks (at the rate of Timer2)   
               PORTB = 0;
               PORTD = 0;
   }else{
       //leg 1
       if(counter<ref_a){
              PORTB &= ~0x01;      PORTD |= 0x08;
       }else if(counter<ref_a+DEAD_TIME*50){
              PORTB &= ~0x01;      PORTD &= ~0x08;
       }else{
              PORTB |= 0x01;       PORTD &= ~0x08;   
       }
   
    //leg 2
       if(counter<ref_b){
              PORTD &= ~0x10;      PORTD |= 0x20;
       }else if(counter<ref_b+DEAD_TIME*50){
              PORTD &= ~0x10;      PORTD &= ~0x20;
       }else{
              PORTD |= 0x10;       PORTD &= ~0x20;      
       }
 
    //leg 3
       if(counter<ref_c){
              PORTD &= ~0x40;     PORTD |= 0x80; 
       }else if(counter<ref_c+DEAD_TIME*50){
              PORTD &= ~0x40;     PORTD &= ~0x80;
       }else{
              PORTD |= 0x40;      PORTD &= ~0x80;   
       }  
   }
   counter= counter+100;       //counter increments
  }
}  


/*****************************************************************************************************/
void loop() {    
}   
//Each while loop: 11.9KHz
