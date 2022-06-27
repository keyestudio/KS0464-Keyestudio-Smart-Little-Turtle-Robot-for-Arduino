/*
keyestudio smart turtle robot 
lesson 13
remote control turtle
http://www.keyestudio.com
*/ 
#include <ks_Matrix.h>
Matrix myMatrix(A4,A5);
//Array, used to store the data of pattern, can be calculated by yourself or obtained from the modulus tool
uint8_t matrix_heart[8]={0x66,0x99,0x81,0x81,0x42,0x24,0x18,0x00};
uint8_t matrix_smile[8]={0x42,0xa5,0xa5,0x00,0x00,0x24,0x18,0x00};
uint8_t matrix_front2[8]={0x18,0x24,0x42,0x99,0x24,0x42,0x81,0x00};
uint8_t matrix_back2[8]={0x00,0x81,0x42,0x24,0x99,0x42,0x24,0x18};
uint8_t matrix_left2[8]={0x48,0x24,0x12,0x09,0x09,0x12,0x24,0x48};
uint8_t matrix_right2[8]={0x12,0x24,0x48,0x90,0x90,0x48,0x24,0x12};
uint8_t matrix_stop2[8]={0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18};
uint8_t  LEDArray[8];
const int left_ctrl = 4;//define the direction control pin of A motor
const int left_pwm = 5;//define the speed control of A motor
const int right_ctrl = 2;//define the direction control pin of B motor 
const int right_pwm = 6;//define the speed control pin of B motor 
#include <IRremote.h>//function library of IR remote control
int RECV_PIN = A1;//set the pin of IR receiver to A1
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;
void setup()
{
  pinMode(left_ctrl,OUTPUT);//
  pinMode(left_pwm,OUTPUT);//
  pinMode(right_ctrl,OUTPUT);//
  pinMode(right_pwm,OUTPUT);//
    Serial.begin(9600);//
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
 myMatrix.begin(112);
 myMatrix.clear();
}
void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//serial prints the read IR remote signals 
    switch(irr_val)
    {
      case 0xFF629D : car_front(); 
      myMatrix.clear();
      myMatrix.writeDisplay();
      matrix_display(matrix_front2);  
      break;
      
      case 0xFFA857 : car_back(); 
      myMatrix.clear();
      myMatrix.writeDisplay();
      matrix_display(matrix_back2); 
      break;
      case 0xFF22DD : car_left(); 
      myMatrix.clear();
      myMatrix.writeDisplay();
      matrix_display(matrix_left2); 
      break;
     
      case 0xFFC23D : car_right();
      myMatrix.clear();
      myMatrix.writeDisplay();
      matrix_display(matrix_right2); 
      break;
     
      case 0xFF02FD : car_Stop();
      myMatrix.clear();
      myMatrix.writeDisplay();
      matrix_display(matrix_stop2); 
      break;
    }
        irrecv.resume(); // Receive the next value
  }
}
void car_front()//define the state of going front
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void car_back()//define the status of going back
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}
void car_left()//set the status of left turning
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}
void car_right()//set the status of right turning
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void car_Stop()//define the state of stop
{
   analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
}
//The function that dot matrix shows pattern
void matrix_display(unsigned char matrix_value[])
{
  for(int i=0; i<8; i++)
    {
      LEDArray[i]=matrix_value[i];
      for(int j=7; j>=0; j--)
      {
        if((LEDArray[i]&0x01)>0)
        myMatrix.drawPixel(j, i,1);
        LEDArray[i] = LEDArray[i]>>1;
      }
    } 
    myMatrix.writeDisplay();
}
