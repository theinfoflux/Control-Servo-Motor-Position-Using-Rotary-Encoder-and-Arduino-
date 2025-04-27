#include <Servo.h>

int dt_pin = 2;
int clk_pin = 3;
int clk_old = 0;
int cnt = 0;
int steps = 5;         //change as per needs

Servo  servomotor;

void setup() 
{
  Serial.begin(9600);
  pinMode(dt_pin, INPUT);
  pinMode(clk_pin, INPUT);
  servomotor.attach(6);
}

void loop() 
{
  
  int dt = digitalRead(dt_pin);
  int clk = digitalRead(clk_pin);
  
 if(clk != clk_old)    // Check for transition
 {
   if(clk != dt)       // Check for CW Direction
   {
    Serial.print("Direction:");
    Serial.println("CW");
    cnt = cnt + steps;
    if(cnt > 180)
    {
      cnt = 180;
    }
    Serial.println(cnt);
   }
   if(clk == dt)        // Check for CCW Direction  
   {
    Serial.print("Direction:");
    Serial.println("CCW");
    cnt = cnt - steps;
    if(cnt < 0)
    {
      cnt = 0;
    }
    Serial.println(cnt);
   }
 }
   servomotor. write(cnt);
   clk_old = clk;     // Store Clk value every cycle
}
