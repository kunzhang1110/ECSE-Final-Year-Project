void setup() {
  pinMode(2,OUTPUT);
  while(1){
      PORTD |= 0x04; 
      PORTD &= ~0x04; 
//      digitalWrite(2, HIGH);
//      digitalWrite(2, LOW);
  }
}

//void loop() {

//}

void loop(){

}
