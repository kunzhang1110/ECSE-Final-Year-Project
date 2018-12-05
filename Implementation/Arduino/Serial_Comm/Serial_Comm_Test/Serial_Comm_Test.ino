byte byteRead= 0;
int counter= 1;
int FREQ= 0;

void setup() {                
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}
void loop() {

    while(counter<=13){
      if (Serial.available()) {       //check data availability
        byteRead = Serial.read();
      }
      if(byteRead>47){
        switch(counter){
        case 1:
          FREQ+= (byteRead-48)*100;
          break;
        case 2:
          FREQ+= (byteRead-48)*10;
          break;
        case 3:
          FREQ+= (byteRead-48);
          break;
        }
      }
            counter++;
    }
//  if (Serial.available()) {       //check data availability
//    byteRead = Serial.read();
//    FREQ+= (byteRead-48)*100;
//    if (Serial.available()) {       //check data availability
//      byteRead = Serial.read();
//      FREQ+= (byteRead-48)*10;
//      if (Serial.available()) {       //check data availability
//        byteRead = Serial.read();
//        FREQ+= (byteRead-48);
//      }
//    }
//
//  }





  Serial.println(FREQ);
  if(FREQ==300){
    digitalWrite(3,HIGH);
    delay(2);
  }
  //  else
  //  {
  //    digitalWrite(3, LOW);
  //    delay(10);
  //  }  
}




