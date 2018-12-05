byte byteRead [2]= {};
int Read_counter= 0;
int n= 0;

void setup() {                
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
//  if (Serial.available()){
//    byteRead[Read_counter] = Serial.read();         
//    while(Read_counter<=1){       //check data availability 
//      if(Serial.available()){
//        Read_counter++; 
//        byteRead[Read_counter] = Serial.read(); 
//       
//      }  
//    }
//  }
 // if (Serial.available()){
    byteRead[0] = Serial.read();  
    byteRead[1] = Serial.read(); 
    if (((byteRead[0]-48)*10+(byteRead[1]-48))<200){
    n= (byteRead[0]-48)*10+(byteRead[1]-48);   
    }
  Serial.println(n);
  delay(2000);
//  if(n==12){
//    digitalWrite(3,HIGH);
//    delay(3);
//    Read_counter= 0;
//  }
}







