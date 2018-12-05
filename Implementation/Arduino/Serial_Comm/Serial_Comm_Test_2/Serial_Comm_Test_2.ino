byte byteRead [5]= {};
int counter= 0;
int FREQ= 0;
int toggle= 0;

void setup() {                
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()){
    if(counter<=5){       //check data availability
      byteRead[counter] = Serial.read();        
      counter++;
    }
  }
  if (counter==5){
  FREQ= (byteRead[0]-48)*100+(byteRead[1]-48)*10+(byteRead[2]-48);
  counter=0;
  }

  if(FREQ==365){
    FREQ=0;
    byteRead[0]= 0;
    byteRead[1]= 0;
    byteRead[2]= 0;
    byteRead[3]= 0;
    byteRead[4]= 0;    
    byteRead[5]= 0; 
    digitalWrite(13,HIGH);
    counter= 0;
  }
  if(FREQ==200){
    FREQ=0;   
    byteRead[0]= 0;
    byteRead[1]= 0;
    byteRead[2]= 0;
    byteRead[3]= 0;
    byteRead[4]= 0;
    byteRead[5]= 0;     
    digitalWrite(13,LOW);
    counter= 0;
  }


  //  if(FREQ==365){
  //    FREQ=0;
  //    byteRead[0]= 0;
  //    byteRead[1]= 0;
  //    byteRead[2]= 0;    
  //    if(toggle==0){
  //      digitalWrite(13,HIGH);
  //      counter= 0;
  //      toggle=1;
  //    }
  //    else{
  //      digitalWrite(13,LOW);
  //      counter= 0;
  //      toggle= 0;
  //    }
  //    delay(1);
  //  }


  //  if(Serial.available()){
  //    digitalWrite(13,HIGH);
  //    delay(2);
  ////    counter= 0;  
  //  }
  // Serial.println(counter);
  // Serial.print(FREQ);
}









