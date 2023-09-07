/* 
1- data ------>13
2-command ------>12
3-vibration
4-gnd
5-3.3v
6-attention ------>A0
7-clock ------>8
8-desconsolad
9-acknokelage
*/
#define motor1_1 10
#define motor1_2 11

#define motor2_1 1
#define motor2_2 2

#define clock 8
#define command 12
#define attention A0
#define data 13



#include <PS2X_lib.h>
PS2X ps2x;
int error=0;
byte vaibrate=0;

void setup(){
  Serial.begin(9600);

  //config_gamepad(clock, command, attention, data, Pressures?, Rumble?)
  error = ps2x.config_gamepad(clock, command, attention, data, true, true);
  if (error==0){ 
    Serial.println("configration done!!");
  }
  else{
    Serial.println("error");
  }

  //input pin for motor 1
  pinMode(motor1_1, OUTPUT);        
  pinMode(motor1_2, OUTPUT);  

  //configration buttons

  /*ps2x.Button(PSB_L1);
  ps2x.Button(PSB_L2);
  ps2x.Button(PSB_L3);
  ps2x.Button(PSB_R1);
  ps2x.Button(PSB_R2);
  ps2x.Button(PSB_R3);
  ps2x.Button(PSB_PAD_UP);
  ps2x.Button(PSB_PAD_DOWN);
  ps2x.Button(PSB_PAD_RIGHT);
  ps2x.Button(PSB_PAD_LEFT);  
  ps2x.Button(PSB_START);
  ps2x.Button(PSB_SELECT);
  */
}

void loop(){
  /*ps2x.Analog(PSS_LX);
  ps2x.Analog(PSS_RX);
  ps2x.Analog(PSS_LY);
  ps2x.Analog(PSS_RY);*/
  ps2x.read_gamepad(false,vaibrate); //vibrate all time
  //vaibrate= ps2x.Analog(PSB_R3);

    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);

  // if cases
  while(ps2x.Button(PSB_BLUE)){
    Serial.println("x pressed");
  }

  while(ps2x.Button(PSB_PINK)){
    Serial.println("square pressed");
  }

  while(ps2x.Button(PSB_RED)){
    Serial.println("o pressed");
  }

  while(ps2x.Button(PSB_GREEN)){
    Serial.println("throw pressed");
  }

  while(ps2x.Button(PSB_L1)){
    Serial.println("L1 pressed");
  }

  while(ps2x.Button(PSB_L2)){
    Serial.println("L2 pressed");
  }

  while(ps2x.Button(PSB_L3)){
    Serial.println("L3 pressed");
  }

  while(ps2x.Button(PSB_R1)){
    Serial.println("R1 pressed");
  }

  while(ps2x.Button(PSB_R2)){
    Serial.println("R2 pressed");
  }

  while(ps2x.Button(PSB_R3)){
    Serial.println("R3 pressed");  
  }

  while(ps2x.Button(PSB_PAD_UP)){
    Serial.println("UP pressed");
    digitalWrite(motor1_1, HIGH);
    digitalWrite(motor1_2, LOW);
  }

  while(ps2x.Button(PSB_PAD_DOWN)){
    Serial.println("DOWN pressed");
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, HIGH);
  }

  while(ps2x.Button(PSB_PAD_RIGHT))
  {
    Serial.println("RIGHT pressed");
    digitalWrite(motor2_1, HIGH);
    digitalWrite(motor2_2, LOW);
  }

  while(ps2x.Button(PSB_PAD_LEFT)){
    Serial.println("LEFT pressed");
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, HIGH);
  }
  
  while(ps2x.Button(PSB_START)){
    Serial.println("START pressed");
  }

  while(ps2x.Button(PSB_SELECT)){
    Serial.println("SELECT pressed");
  }

  /*
  if(ps2x.Analog(PSS_LX)||ps2x.Analog(PSS_RX))
    {
    Serial.print(ps2x.Analog(PSS_LX),DEC); 
    delay(50);
    }

  if(ps2x.Analog(PSS_LY)||ps2x.Analog(PSS_RY))
    {
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LY),DEC);
    Serial.println("");
    delay(50);
    } 
    
  */

  delay(10);

}