#include <Servo.h>           
Servo servo1;               
Servo servo2;
int joystick_x = A0;                                                    
int joystick_y = A1;                                                     
int pos_x;                   
int pos_y;                   
int servo1_pos=90;          
int servo2_pos=90;
void setup ( ) {
pinMode(8, INPUT_PULLUP);
servo1.attach (5) ;         
servo2.attach (6) ;          
servo1.write (servo1_pos);           
servo2.write (servo2_pos);
pinMode (joystick_x, INPUT) ;                     
pinMode (joystick_y, INPUT) ;                      
}
void loop ( ) {
pos_x = analogRead (joystick_x) ;  
pos_y = analogRead (joystick_y) ;                      
if (pos_x < 300)            
{
  if (servo1_pos < 10)      
  { 
  } 
  else
  { 
    servo1_pos = servo1_pos - 10; 
    servo1.write ( servo1_pos ) ; 
    delay (100); 
  } 
} 
if (pos_x > 700)
{
  if (servo1_pos > 180)
  {  
  }  
  else
  {
  servo1_pos = servo1_pos + 10;
  servo1.write ( servo1_pos ) ;
  delay (100) ;
  }
}
if (pos_y < 300)     
{
  if (servo2_pos < 10)  
  { 
  } 
  else
  { 
    servo2_pos = servo2_pos - 10; 
    servo2.write ( servo2_pos ); 
    delay (100); 
  } 
} 
if (pos_y > 700)
{
  if (servo2_pos > 180)
  {  
  }        
  else
  {
  servo2_pos = servo2_pos + 10;
  servo2.write(servo2_pos) ;
  delay (100) ;
  }
}
 int SW_pin = digitalRead(8);
   if(SW_pin == LOW)
  {
    servo1.write (90);           
    servo2.write (90);
    delay(500);
   }
}