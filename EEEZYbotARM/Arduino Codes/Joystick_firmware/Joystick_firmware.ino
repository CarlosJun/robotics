/********************************
 * @author: Francisco Carlos Freire N. JR.
 * @date: 21/04/2017
 *********************************/

#include <Servo.h> 
#define ABERTO true
#define FECHADO false

Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

// Pino analgico do potenciometro
int pino_x = A0; 
int pino_y = A1; 
int pino_z = A2; 
int pino_k = A3; 

int analog_1;
int analog_2;
int analog_3;
int analog_4;
int incPos1;
int incPos2;
int position1;
int position2;
int position3;
int position4;
boolean key;
int button;

void setup() 
{ 
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  
  Serial.begin(9600); 
   
  analog_1 = 0;
  analog_2 = 0;
  analog_3 = 0;
  analog_4 = 0;
  incPos1 = 0;
  incPos1 = 0;
  position1 = 1;
  position2 = 1;
  position3 = 1;
  position4 = 1;
  key = FECHADO;
  button = 1;
  
  
} 

void loop() 
{           
  analog_1 = analogRead(pino_x);
  analog_2 = analogRead(pino_y); 
  analog_3 = analogRead(pino_z);
  analog_4 = analogRead(pino_k);

  position4 = (int) map(analog_4,0,700,1,90);

  //Serial.println(analog_1);
  //Serial.println(analog_2);
  //Serial.println(analog_3);
  //Serial.println(analog_4);
  
  if(analog_1 >= 500 && analog_1 <=550)
  {
    incPos1 = 0;
  }
  else if(analog_1 > 550)
  {
    incPos1 = (int) map(analog_1,551,1023,1,10); 
  }
  else if(analog_1 < 500)
  {
    incPos1 = (int) map(analog_1,499,0,-1,-10); 
  }

  if(analog_2 >= 400 && analog_2 <=650)
  {
    incPos2 = 0;
  }
  else if(analog_2 > 650)
  {
    incPos2 = (int) map(analog_2,651,1023,1,10); 
  }
  else if(analog_2 < 400)
  {
    incPos2 = (int) map(analog_2,399,0,-1,-10); 
  }

  if(analog_3 <= 100 && button == 1 && analog_2 >300)
  {
    button = 0;
  }
  else if(analog_3 > 100 && button == 0)
  {
    button = 2;
  }

  if(button == 2)
  {
    if(key == ABERTO)
    {
      key = FECHADO;
      position3 = 1;
    }
    else if(key == FECHADO)
    {
      key = ABERTO;
      position3 = 80;
    }
    button = 1;
  }

  position1 += incPos1;
  position2 += incPos2;
  
  if(position1 >= 130)
  {
    position1 = 130;
  }
  if(position1 <= 0)
  {
    position1 = 1;
  }

  if(position2 >= 120)
  {
    position2 = 120;
  }
  if(position2 <= 0)
  {
    position2 = 1;
  }
  
  /*Serial.println(position1);
  Serial.println(position2);
  Serial.println(position3);
  Serial.println();*/
  
  servo1.write(position1);
  servo2.write(position2);
  servo3.write(position3);
  servo4.write(position4);

  delay(100);
              
}
