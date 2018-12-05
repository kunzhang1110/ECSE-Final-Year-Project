#define LOOP_EXEC_TIME 0.00008333      //execution time of loop without analogueRead
#define REF_FREQUENCY 300
#define DEAD_TIME 3                    //dead time in micro seconds
#define SINE_TABLE_MAX 20
#define FEEDBACK_GAIN 0
#define PROP_GAIN 1
//measure ADC exeuction time
int a= 0;
int b= 0;
int toggle= 1;
int sin_table[21]={
  500, 655, 794, 905, 976, 1000,976, 905, 794, 655, 500,355, 206, 95, 24, 0, 24, 95, 206, 345, 500};
int ref_a= 0;
int ref_b= 0;
int i=0;
int j=0;
int ctrl_a= 0;
int fb_a= 0;
int fb_b= 0;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  //   pinMode(A1,INPUT);
  ADCSRA=  0x84;                              //set ADC prescalar to 16; enable ADC conversion
  //    TCCR0B= _BV(CS00)|_BV(CS01);                //default Timer0 prescaler of 64
  while(1){
    PORTD |= 0x04;
    if(toggle){
      a= analogRead(A0);
      PORTD &= ~0x10;     
      PORTD |= 0x20;
      PORTD &= ~0x10;     
      PORTD |= 0x20;
      PORTD &= ~0x10;     
      PORTD |= 0x20;      
      toggle=0;
            ref_a= sin_table[i];                          //set ref_phase to a scale of 0 to COUNT_MAX
i++;
      ctrl_a= (ref_a-fb_a*FEEDBACK_GAIN)*PROP_GAIN;  
    }
    else{
      b= analogRead(A1);
      PORTD &= ~0x10;    
      PORTD &= ~0x10;     
      PORTD |= 0x20;
      PORTD &= ~0x10;     
      PORTD |= 0x20;
      PORTD &= ~0x10;     
      PORTD |= 0x20;
      toggle=1;  
    }
    PORTD &= ~0x04;
      ref_b= sin_table[j];   
            ctrl_a= (ref_a-fb_a*FEEDBACK_GAIN)*PROP_GAIN;  
  j++;
   }  
}
//Measuring using oscilloscope, execution time: 32.7 us - 0.3us

//void setup() {
//    Serial.begin(115200);
//    ADCSRA=  0x00;                              //set ADC prescalar to 2
//    TCCR0B= _BV(CS00)|_BV(CS01);                //default Timer0 prescaler of 64
//    while(1){
//      Serial.println(micros());
//      a= analogRead(A0);
//      b= analogRead(B0);
//      Serial.println(micros());
//    }  
//}
////Measuring using Serial.println, execution time: 200 us

void loop() {
  //empty loop
}  

