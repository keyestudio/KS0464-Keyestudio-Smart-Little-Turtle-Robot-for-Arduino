/*
 keyestudio smart turtle robot
 lesson 9.2
 Matrix
 http://www.keyestudio.com
*/ 
#include <Matrix.h>
Matrix myMatrix(A4,A5);    //set pins to communication pins
//define an array
uint8_t LedArray1[8]={0x66,0x99,0x81,0x81,0x42,0x24,0x18,0x00};  
uint8_t  LEDArray[8]; //define an array(by modulus tool) without initial value
void setup(){
  myMatrix.begin(0x70);  //communication address
  myMatrix.clear();    //Clear
}
void loop(){
  for(int i=0; i<8; i++)  // there is eight data, loop for eight times
  {
    LEDArray[i]=LedArray1[i];  //Call the emoticon array data in the subroutine LEDArray
    for(int j=7; j>=0; j--)  //Every data(byte) has 8 bits, therefore, loop for eight times

    {
      if((LEDArray[i]&0x01)>0) //judge if the last bit of data is greater than 0
      {
        myMatrix.drawPixel(j, i,1);  //light up the corresponding point
      }
      else  //otherwise
      {
        myMatrix.drawPixel(j, i,0);  //turn off the corresponding point 
      }
      LEDArray[i] = LEDArray[i]>>1;  //LEDArray[i] moves right for one bit to judge the previous one bit
    }
  }
  myMatrix.writeDisplay();  // dot matrix shows
}
//**************************************************************************
