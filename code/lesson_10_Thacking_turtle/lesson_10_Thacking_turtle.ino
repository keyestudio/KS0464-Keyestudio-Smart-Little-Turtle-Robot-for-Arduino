/*
 keyestudio smart turtle robot
 lesson 10
 Thacking turtle
 http://www.keyestudio.com
*/ 
int left_ctrl = 2;//define direction control pin of A motor
 int left_pwm = 6;//define PWM control pin of A motor
 int right_ctrl = 4;//define direction control pin of B motor
 int right_pwm = 5;//define PWM control pin of B motor
 int sensor_l = 11;//define the pin of left line tracking sensor
 int sensor_c = 7;//define the pin of middle line tracking sensor
 int sensor_r = 8;//define the pin of right line tracking sensor
int l_val,c_val,r_val;//define these variables

void setup() {
  Serial.begin(9600);//start serial monitor and set baud rate to 9600
  pinMode(left_ctrl,OUTPUT);//set direction control pin of A motor to OUTPUT
  pinMode(left_pwm,OUTPUT);//set PWM control pin of A motor to OUTPUT
  pinMode(right_ctrl,OUTPUT);//set direction control pin of B motor to OUTPUT
  pinMode(right_pwm,OUTPUT);//set PWM control pin of B motor to OUTPUT
  pinMode(sensor_l,INPUT);//set the pins of left line tracking sensor to INPUT
  pinMode(sensor_c,INPUT);//set the pins of middle line tracking sensor to INPUT
  pinMode(sensor_r,INPUT);//set the pins of right line tracking sensor to INPUT
}

void loop() 
{
  tracking(); //run main program
}

void tracking()
{
  l_val = digitalRead(sensor_l);//read the value of left line tracking sensor
  c_val = digitalRead(sensor_c);//read the value of middle line tracking sensor
  r_val = digitalRead(sensor_r);//read the value of right line tracking sensor

  if(c_val == 1)//if the state of middle one is 1, which means detecting black line

  {
    front();//car goes forward
  }
  else
  {
    if((l_val == 1)&&(r_val == 0))//if only left line tracking sensor detects black trace

    {
      left();//car turns left
    }
    else if((l_val == 0)&&(r_val == 1))///if only right line tracking sensor detects black trace

    {
      right();//car turns right
    }
    else//if none of line tracking sensor detects black line
    {
      Stop();//car stops
    }
  }
}
void front()//define the status of going forward
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void back()//define the state of going back
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}
void left()//define the left-turning state
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void right()//define the right-turning state
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
