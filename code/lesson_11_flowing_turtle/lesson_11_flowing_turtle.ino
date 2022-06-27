/*
 keyestudio smart turtle robot
 lesson 11
 flowing turtle
 http://www.keyestudio.com
*/ 

 int left_ctrl = 2;//define the direction control pin of A motor
 int left_pwm = 6;//define the speed control pin of A motor
 int right_ctrl = 4;//define the direction control pin of B motor
 int right_pwm = 5;//define the speed control pin of B motor
#include "SR04.h" //define the function library of ultrasonic sensor
#define TRIG_PIN 12// set the signal of ultrasonic sensor to D12
#define ECHO_PIN 13// set the signal of ultrasonic sensor to D13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

void setup() {
  Serial.begin(9600);//open serial monitor and set baud rate to 9600
  pinMode(left_ctrl,OUTPUT);//set direction control pin of A motor to OUTPUT
  pinMode(left_pwm,OUTPUT);//set PWM control pin of A motor to OUTPUT
  pinMode(right_ctrl,OUTPUT);//set direction control pin of B motor to OUTPUT
  pinMode(right_pwm,OUTPUT);//set PWM control pin of B motor to OUTPUT

}

void loop() {
  distance = sr04.Distance();//the distance detected by ultrasonic sensor
   if(distance<8)//if distance is less than 8
  {
    back();//go back
  }
  else if((distance>=8)&&(distance<13))//if 8≤distance＜13
  {
    Stop();//stop
  }
  else if((distance>=13)&&(distance<35))//if 13≤distance＜35  
{
    front();//follow
  }
  else//otherwise
  {
    Stop();//stop
  }
}

void front()//define the status of going front
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void back()//define the status of going back
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}
void left()//define the status of turning left
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void right()//define the status of right turning
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}
void Stop()//define the state of stop
{
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
}
//*********************************************************
