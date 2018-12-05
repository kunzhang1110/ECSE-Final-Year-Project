#include <avr/io.h>
#include <math.h>
/******************************************************************************************************/
/*This code is to use preset reference signal freqeucies and generate PWM in open loop                */
/*No delay                                                                                            */
/*                                                                                                    */
/******************************************************************************************************/
/*Frequencies of reference signals*/
int ref_freq= 300;          //reference AC frequency
int ref_amp= 1;             //refrence AC amplitude  

/*set pin numbers*/
int ref_a_Pin= A0;         //select A0,A1 for reference signals
int ref_b_Pin= A1;
int fdb_a_Pin= A2;         //select A2,A3 for feedback signals
int fdb_b_Pin= A3;

/*pwm pins*/
int pwm_1_Pin= 6;          //OC0A, Timer 0
int pwm_2_Pin= 5;          //OC0B, Timer 0
int pwm_3_Pin= 9;          //0C1A, Timer 1
int pwm_4_Pin= 10;         //OC1B, Timer 1
int pwm_5_Pin= 11;         //OC2A, Timer 2
int pwm_6_Pin= 3;          //OC2B, Timer 2

/*initialize variables*/
double duty_cycle_1= 0;
double duty_cycle_2= 0;
double duty_cycle_3= 0;
double ref_a_sample= 0;
double ref_b_sample= 0;
double ref_c_sample= 0;

/*sine table*/
int sine_table[] =
{
127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,2
10,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,242,243,244,245,247,248,249,249,250,251,252,252,25
3,253,253,254,254,254,254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234
,233,231,229,227,225,223,221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,
161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,76,73,70,67,64,
62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,
2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,
90,93,96,99,102,105,108,111,115,118,121,124
}
/******************************************************************************************************/
void setup(){
  //declare outputs
  pinMode(pwm_1_Pin, OUTPUT);
  pinMode(pwm_2_Pin, OUTPUT);  
  pinMode(pwm_3_Pin, OUTPUT);  
  pinMode(pwm_4_Pin, OUTPUT);  
  pinMode(pwm_5_Pin, OUTPUT);  
  pinMode(pwm_6_Pin, OUTPUT);    
  setTimerRegisters();        //set Timer module 0, 1, 2
  Serial.begin(9600);        // initialize serial communications at 9600 bps:
}  


/******************************************************************************************************/
void loop() {
//leg 1 (Timer 0)
  if(TCNT0==255){                                                     //when the counter reaches maximmum (256)
        ref_a_sample= ref_amp*sin(2*M_PI*ref_freq*millis());          //sample reference signal
        duty_cycle_1= (ref_a_sample+ref_amp)/(2*ref_amp);
        OCR0A = duty_cycle_1*255;
        OCR0B = duty_cycle_1*255;
  }

//leg 2 (Timer 1)
  if(TCNT1==255){                                                          //when the counter reaches maximmum (256)
       ref_b_sample= ref_amp*sin(2*M_PI*ref_freq*millis()+2*M_PI/3);       //sample reference signal
       duty_cycle_2= (ref_b_sample+ref_amp)/(2*ref_amp);
       OCR1A= duty_cycle_1*255;
       OCR1B= duty_cycle_1*255;
   }

//leg 3 (Timer 2)
  if(TCNT2==255){                                                         //when the counter reaches maximmum (256)
      ref_c_sample= ref_amp*sin(2*M_PI*ref_freq*millis()+4*M_PI/3);       //sample reference signal
      duty_cycle_3= (ref_c_sample+ref_amp)/(2*ref_amp);
      OCR2A = duty_cycle_1*255;
      OCR2B = duty_cycle_1*255;
  }
}


/******************************************************************************************************/
void setTimerRegisters(){                                                      //set timer registers to operate in fast PWM mode
  /*Set Timer 0*/
  TCCR0A= _BV(COM0A1)|_BV(COM0B1)|_BV(COM0B0)|_BV(WGM01)|_BV(WGM00);           //set output A to non-inverting, B to inverting; set both to fast PWM
  TCCR0B= _BV(CS00);                                                           //no prescaling
   /*Set Timer 1*/
  TCCR1A= _BV(COM1A1)|_BV(COM1B1)|_BV(COM1B0)|_BV(WGM11)|_BV(WGM10);           //set output A to non-inverting, B to inverting; set both to fast PWM
  TCCR1B= _BV(CS10);                                                           //no prescaling
   /*Set Timer 2*/
  TCCR2A= _BV(COM2A1)|_BV(COM2B1)|_BV(COM2B0)|_BV(WGM21)|_BV(WGM20);           //set output A to non-inverting, B to inverting; set both to fast PWM
  TCCR2B= _BV(CS20);                                                           //no prescaling 
}
//TCCR0B= _BV(CS00)|_BV(CS01);                                                 //default prescale of 64
