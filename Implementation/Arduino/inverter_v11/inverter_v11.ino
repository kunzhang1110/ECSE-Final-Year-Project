#include <math.h>
#define ADCLOOP_EXEC_TIME 0.0001429    //execution time of loops with analogueRead
#define LOOP_EXEC_TIME 0.00008333      //execution time of loop without analogueRead
#define DEAD_TIME 3                    //dead time in micro seconds
#define SINE_TABLE_MAX 255
#define FEEDBACK_GAIN 0
#define PROP_GAIN 1
/******************************************************************************************************/
/*    This code is to use preset reference signal freqeucies and generate PWM in close loop           */
/*    Version 8, based on SIMULINK code  sim_Motor_2kW_closedloop_v8_delay                            */
/*    Identical loop time                                                                             */
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
byte byteRead [3]= {48,56};
int Read_counter= 0;

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
int down_flag= 0;                  //flag for downward counting
int sin_table[255]={777,787,797,807,817,826,835,844,853,862,870,878,886,894,901,908,915,922,928,935,940,946,951,957,961,966,970,974,978,981,985,987,990,992,994,996,997,998,999,999,1000,999,999,998,997,996,994,992,990,987,985,981,978,974,970,966,961,957,951,946,940,935,928,922,915,908,901,894,886,878,870,862,853,844,835,826,817,807,797,787,777,767,757,746,735,724,713,702,691,679,668,656,645,633,621,60,597,585,573,561,549,536,524,512,500,487,475,463,450,438,426,414,402,390,378,366,354,343,331,320,308,297,286,275,264,253,242,232,222,212,202,192,182,173,164,155,146,137,129,121,113,105,98,91,84,77,71,64,59,53,48,42,38,33,29,25,21,18,14,12,9,7,5,3,2,1,0,0,0,0,0,1,2,3,5,7,9,12,14,18,21,25,29,33,38,42,48,53,59,64,71,77,84,91,98,105,113,121,129,137,146,155,164,173,182,192,202,212,222,232,242,253,264,275,286,297,308,320,331,343,354,366,378,390,402,414,426,438,450,463,475,487};
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
  //declare inputs
  pinMode(fdb_a_Pin, INPUT);
  pinMode(fdb_b_Pin, INPUT); 
  Serial.begin(115200); 
  ADCSRA=  0x84;                               //set ADC prescalar to 16; enable ADC conversion
  TCCR0B= _BV(CS00)|_BV(CS01);                 //default Timer0 prescaler of 64
}

/*****************************************************************************************************/
void loop() { 


  //     Serial.println(n);
  if(counter==counter_max||counter==0){            //if counter reaches maximum, take new values

    if (Serial.available()){
      byteRead[0] = Serial.read();  
      byteRead[1] = Serial.read(); 
      byteRead[2] = Serial.read(); 
      if(byteRead[0]<255&&byteRead[1]<255){
          n=(byteRead[0]-48)*10+(byteRead[1]-48);  
      }  
    }
//    Serial.println(n);
    if(i>SINE_TABLE_MAX){
      i= 0;
    }
    else{
      i= i+n;
    } 
    if(j>SINE_TABLE_MAX){
      j= 0;   
    }
    else{
      j= j+n;
    }
    ref_a= sin_table[i];                          //set ref_phase to a scale of 0 to COUNT_MAX
    ref_b= sin_table[j];            
    ref_c= (-ref_a-ref_b)+3/2*counter_max;        //obtain ref_c from ref_a and ref_b
    fb_a=analogRead(fdb_a_Pin);
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
  }
  else if (counter==counter_max){
    down_flag= 1;           //flag count down
  }
  if (counter==100){
    fb_b=analogRead(fdb_b_Pin);
  }

  /*Count up*********************************************************/
  if(down_flag==0){
    if(counter<ctrl_a){
      PORTB &= ~0x01;      
      PORTD |= 0x08;
    }
    else if(sem_1==0) {
      PORTB &= ~0x01;      
      PORTD &= ~0x08;
      delayMicroseconds(DEAD_TIME);
      PORTB |= 0x01;       
      PORTD &= ~0x08; 
      sem_1= 1;  
    }
    else{
      PORTB |= 0x01;       
      PORTD &= ~0x08;         
    }

    //leg 2
    if(counter<ctrl_b){
      PORTD &= ~0x10;      
      PORTD |= 0x20;
    }
    else if(sem_2==0) {
      PORTD &= ~0x10;      
      PORTD &= ~0x20;
      delayMicroseconds(DEAD_TIME);
      PORTD |= 0x10;       
      PORTD &= ~0x20; 
      sem_2= 1;  
    }
    else{
      PORTD |= 0x10;       
      PORTD &= ~0x20;         
    } 

    //leg 3
    if(counter<ctrl_c){
      PORTD &= ~0x40;      
      PORTD |= 0x80;
    }
    else if(sem_3==0) {
      PORTD &= ~0x40;      
      PORTD &= ~0x80;
      delayMicroseconds(DEAD_TIME);
      PORTD |= 0x40;       
      PORTD &= ~0x80; 
      sem_3= 1;  
    }
    else{
      PORTD |= 0x40;       
      PORTD &= ~0x80;         
    }
    counter= counter+100;  
  }  
  /*Count down*********************************************************/
  else{
    if(counter>ctrl_a){
      PORTB |= 0x01;       
      PORTD &= ~0x08;              
    }
    else if(sem_1==0) {
      PORTB &= ~0x01;      
      PORTD &= ~0x08;
      delayMicroseconds(DEAD_TIME);
      PORTB &= ~0x01;      
      PORTD |= 0x08;    
      sem_1= 1;  
    }
    else{
      PORTB &= ~0x04;      
      PORTD |= 0x08;    
    }

    //leg 2
    if(counter>ctrl_b){
      PORTD |= 0x10;       
      PORTD &= ~0x20;  
    }
    else if(sem_2==0) {
      PORTD &= ~0x10;      
      PORTD &= ~0x20;
      delayMicroseconds(DEAD_TIME);
      PORTD &= ~0x10;      
      PORTD |= 0x20; 
      sem_2= 1;  
    }
    else{
      PORTD &= ~0x10;      
      PORTD |= 0x20;      
    } 

    //leg 3
    if(counter<ctrl_c){
      PORTD |= 0x40;       
      PORTD &= ~0x80;  
    }
    else if(sem_3==0) {
      PORTD &= ~0x40;      
      PORTD &= ~0x80;
      delayMicroseconds(DEAD_TIME);
      PORTD &= ~0x40;      
      PORTD |= 0x80;    
      sem_3= 1;  
    }
    else{
      PORTD &= ~0x40;      
      PORTD |= 0x80;       
    }
    counter= counter-100;          
  } 
}   









