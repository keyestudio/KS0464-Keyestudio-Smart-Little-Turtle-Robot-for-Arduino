/*
  keyestudio smart turtle robot
 lesson 6.1
 IRremote
 http://www.keyestudio.com
*/ 
#include <IRremote.h>     //IRremote library statement  
int RECV_PIN = A1;        //define the pins of IR receiver as A1
IRrecv irrecv(RECV_PIN);   
decode_results results;   // decode results exist in the“result” of “decode results”
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Enable receiver 
}  
  
 void loop() {  
  if (irrecv.decode(&results))//decode successfully, receive a set of infrared signals  
   {  
     Serial.println(results.value, HEX);//Wrap word in 16 HEX to output and receive code 
     irrecv.resume(); // Receive the next value
   }  
   delay(100);  
 } 
  //*********************************************************
