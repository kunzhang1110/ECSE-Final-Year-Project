//measure Digital IO exeuction time
int pwm_1_Pin= 2;                   
int pwm_2_Pin= 3;                   
int pwm_3_Pin= 4;                  
int pwm_4_Pin= 5;                   
int pwm_5_Pin= 6;                   
int pwm_6_Pin= 7;
int meas_Pin= 8;

void setup() { 
  //declare outputs
  pinMode(pwm_1_Pin, OUTPUT);
  pinMode(pwm_2_Pin, OUTPUT);  
  pinMode(pwm_3_Pin, OUTPUT);  
  pinMode(pwm_4_Pin, OUTPUT);  
  pinMode(pwm_5_Pin, OUTPUT);  
  pinMode(pwm_6_Pin, OUTPUT);
  pinMode(meas_Pin, OUTPUT);
  TCCR0B= _BV(CS00)|_BV(CS01);                            //default Timer0 prescaler of 64
  while(1){
      PORTB |= 0x01;     //set measurement pin
      //60 digital writes
      {
      PORTD &= ~0x04;     PORTD |= 0x08;
      PORTD &= ~0x10;     PORTD |= 0x20;
      PORTD &= ~0x40;     PORTD |= 0x80;
      PORTD |= 0x04;      PORTD &= ~0x08;
      PORTD |= 0x10;      PORTD &= ~0x20;         
      PORTD |= 0x40;      PORTD &= ~0x80;        
      }
      {
      PORTD &= ~0x04;     PORTD |= 0x08;
      PORTD &= ~0x10;     PORTD |= 0x20;
      PORTD &= ~0x40;     PORTD |= 0x80;
      PORTD |= 0x04;      PORTD &= ~0x08;
      PORTD |= 0x10;      PORTD &= ~0x20;         
      PORTD |= 0x40;      PORTD &= ~0x80;        
      } 
      {
      PORTD &= ~0x04;     PORTD |= 0x08;
      PORTD &= ~0x10;     PORTD |= 0x20;
      PORTD &= ~0x40;     PORTD |= 0x80;
      PORTD |= 0x04;      PORTD &= ~0x08;
      PORTD |= 0x10;      PORTD &= ~0x20;         
      PORTD |= 0x40;      PORTD &= ~0x80;        
      }
      {
      PORTD &= ~0x04;     PORTD |= 0x08;
      PORTD &= ~0x10;     PORTD |= 0x20;
      PORTD &= ~0x40;     PORTD |= 0x80;
      PORTD |= 0x04;      PORTD &= ~0x08;
      PORTD |= 0x10;      PORTD &= ~0x20;         
      PORTD |= 0x40;      PORTD &= ~0x80;        
      }
      {
      PORTD &= ~0x04;     PORTD |= 0x08;
      PORTD &= ~0x10;     PORTD |= 0x20;
      PORTD &= ~0x40;     PORTD |= 0x80;
      PORTD |= 0x04;      PORTD &= ~0x08;
      PORTD |= 0x10;      PORTD &= ~0x20;         
      PORTD |= 0x40;      PORTD &= ~0x80;        
      } 
      PORTB &= ~0x01;    //reset measurement pin     
  }  
}
//Measuring using oscilloscope, execution time: 32.7 us - 0.3us


void loop() {
//empty loop
}  
