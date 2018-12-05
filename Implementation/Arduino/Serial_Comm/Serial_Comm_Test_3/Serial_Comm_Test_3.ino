byte byteRead [3]= {};
int counter= 0;
int FREQ= 0;

void setup() {                
  pinMode(3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()){
    if(counter<=2){       //check data availability
      byteRead[counter] = Serial.read();        
      counter++;
    }
  }
  FREQ= (byteRead[0]-48)*100+(byteRead[1]-48)*10+(byteRead[2]-48);

  if(FREQ==365){
    digitalWrite(3,LOW);
    delay(3);
    counter= 0;
  }
  digitalWrite(3,HIGH);
}






