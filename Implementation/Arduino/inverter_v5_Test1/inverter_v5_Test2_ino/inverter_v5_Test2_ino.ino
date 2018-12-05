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
byte byteRead [3]= {48,56};
//initialize variables
double ref_a= 0;
double ref_b= 0;
double ref_c= 0;
int counter= 0;
double fb_a= 0;
double fb_b= 0;
double fb_c= 0;

//define constants
int counter_max= 1000;
int DEAD_TIME= 100;
int SINE_TABLE_MAX= 20;
int FEEDBACK_GAIN= 0;
int PROP_GAIN= 1;
double sin_table[21]={
  500, 655, 794, 905, 976, 1000,976, 905, 794, 655, 500,355, 206, 95, 24, 0, 24, 95, 206, 345, 500};
int i= 0;
int j= 6;
int k =13;
int n= 1;
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
  ADCSRA=  0x84;                                                     //set ADC prescalar to 16; enable ADC conversion
}  


/*****************************************************************************************************/
void loop() { 
  if(counter==counter_max){         //if counter reaches maximum, take new values
    if (Serial.available()){
      byteRead[0] = Serial.read();  
      byteRead[1] = Serial.read(); 
      //      byteRead[2] = Serial.read(); 
      if(byteRead[0]<255&&byteRead[1]<255){
        n=(byteRead[0]-48)*10+(byteRead[1]-48);  
      }
      Serial.println(n);
    }
    if(i==SINE_TABLE_MAX){
      i= 0;
    }
    else{
      i= i+n;
    } 
    if(j==SINE_TABLE_MAX){
      j= 0;
    }
    else{
      j= j+n;
    }      
    if(k==SINE_TABLE_MAX){
      k= 0;
    }
    else{
      k= k+n;
    }       
    ref_a= sin_table[i];                                     //set ref_phase to a scale of 0 to COUNT_MAX
    ref_b= sin_table[j];
    ref_c= sin_table[k];
    ref_c= (ref_c-fb_c*FEEDBACK_GAIN)*PROP_GAIN; 
    fb_a= analogRead(fdb_a_Pin)-540;
    fb_b= analogRead(fdb_b_Pin)-540;
    fb_c=-fb_a-fb_b+2046;
    counter= 0;              //reset counter
    ref_a= (ref_a-fb_a*FEEDBACK_GAIN)*PROP_GAIN; 
    ref_b= (ref_b-fb_b*FEEDBACK_GAIN)*PROP_GAIN; 
  }

  if(counter<DEAD_TIME){                                              //initially, pwm 1->0, delay for 5 ticks (at the rate of Timer2)   
    PORTB= 0;
    PORTD= 0;
  }
  else{
    //leg 1
    if(counter<ref_a){
      PORTB &= ~0x01;      
      PORTD |= 0x08;
    }
    else if(counter<ref_a+DEAD_TIME){
      PORTB &= ~0x01;      
      PORTD &= ~0x08;
    }
    else{
      PORTB |= 0x01;       
      PORTD &= ~0x08;   
    }

    //leg 2
    if(counter<ref_b){
      PORTD &= ~0x10;      
      PORTD |= 0x20;
    }
    else if(counter<ref_b+DEAD_TIME){
      PORTD &= ~0x10;      
      PORTD &= ~0x20;
    }
    else{
      PORTD |= 0x10;       
      PORTD &= ~0x20;      
    }

    //leg 3
    if(counter<ref_c){
      PORTD &= ~0x40;     
      PORTD |= 0x80; 
    }
    else if(counter<ref_c+DEAD_TIME){
      PORTD &= ~0x40;     
      PORTD &= ~0x80;
    }
    else{
      PORTD |= 0x40;      
      PORTD &= ~0x80;   
    }  
  }
  counter= counter+100;       //counter increments

}   
//Each while loop: 11.9KHz

