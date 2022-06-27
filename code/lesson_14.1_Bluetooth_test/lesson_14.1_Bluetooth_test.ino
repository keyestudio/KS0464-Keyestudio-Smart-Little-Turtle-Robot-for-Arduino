/*
keyestudio 
lesson 14.1
Bluetooth test
http://www.keyestudio.com
*/ 
char BLE_val;
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  if(Serial.available()>0)
  {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  }
}
