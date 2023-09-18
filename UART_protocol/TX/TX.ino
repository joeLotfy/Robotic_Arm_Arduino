//استغفر الله العظيم
//TX (Transmitter)
//MASTER Arduino

connections:
TX(10) with RX(13)
common ground
////////////////////////////////////////// 
1- data ------>A0
2-command ------>A1
3-vibration
4-gnd
5-3.3v
6-attention ------>A2
7-clock ------>A3
8-desconsolad
9-acknokelage
*/
#include <SoftwareSerial.h>
#include <PS2X_lib.h>
PS2X ps2x;
int error = 0;
byte vaibrate = 0;
SoftwareSerial myserial(13,10);  //(RX,TX)

//#define motor1_1 2
//#define motor1_2 3

//#define motor2_1 2
//#define motor2_2 3

//#define motor7_1 2  //  car right 
//#define motor7_2 3  // car right

//#define motor8_1 4  // car left
//#define motor8_2 5  // car left

#define led A4

//FUNCTIONS
//motor1
/*void hold(){
  digitalWrite(motor1_1, HIGH);
  digitalWrite(motor1_2, LOW);
}

void let(){
  digitalWrite(motor1_1, LOW);
  digitalWrite(motor1_2, HIGH);
}
/////////////////////////////////////////////
//motor2
void curve_up(){
  digitalWrite(motor2_1, HIGH);
  digitalWrite(motor2_2, LOW);
}

void curve_down(){
  digitalWrite(motor2_1, LOW);
  digitalWrite(motor2_2, HIGH);
} 
/////////////////////////////////////////////
/*
//car
//motors7&8
void backward_car(){
  digitalWrite(motor7_1, LOW);  // right motor
  digitalWrite(motor7_2, HIGH);   // right motor
  digitalWrite(motor8_1, HIGH);  // left motor
  digitalWrite(motor8_2, LOW);  // left motor
}

void forward_car(){
  digitalWrite(motor7_1, HIGH);   // right motor
  digitalWrite(motor7_2, LOW);    // right motor
  digitalWrite(motor8_1, LOW);    // left motor
  digitalWrite(motor8_2, HIGH);   // left motor
}

void stop_car(){
  digitalWrite(motor7_1, LOW);  // right motor
  digitalWrite(motor7_2, LOW);   // right motor
  digitalWrite(motor8_1, LOW);  // left motor
  digitalWrite(motor8_2, LOW);  // left motor
}

void Right_car(){
  digitalWrite(motor7_1, LOW);  // right motor
  digitalWrite(motor7_2, HIGH);  // right motor
  digitalWrite(motor8_1, LOW);  // left motor
  digitalWrite(motor8_2, HIGH);  // left motor
}

void Left_car(){
  digitalWrite(motor7_1, HIGH);   // right motor
  digitalWrite(motor7_2, LOW);    // right motor
  digitalWrite(motor8_1, HIGH);  // left motor
  digitalWrite(motor8_2, LOW);  // left motor
}*/
/////////////////////////////////////////////
//led
void led_on(){
  digitalWrite(led, HIGH);
}

void led_off(){
  digitalWrite(led, LOW);
}
///////////////////////////////////////////////////

void setup(){
  Serial.begin(9600);
  myserial.begin(4800);
  error=ps2x.config_gamepad(A3,A1,A2,A0,true,true);  //(clock,command,attention,data)
  if (error == 0){ 
    Serial.println("configration done!!");
  }
  else{
    Serial.println("error");
  }

  //pin_modes
  
//  pinMode(motor1_1, OUTPUT);        
 // pinMode(motor1_2, OUTPUT);  


 // pinMode(motor2_1, OUTPUT);        
  //pinMode(motor2_2, OUTPUT);
/*
  //car
  pinMode(motor7_1, OUTPUT);
  pinMode(motor7_2, OUTPUT);
  pinMode(motor8_1, OUTPUT);        
  pinMode(motor8_2, OUTPUT);

  pinMode(led, OUTPUT);
  */
}

void loop(){
  ps2x.read_gamepad(false,vaibrate); //vibrate all time
/*
   if(ps2x.Button(PSB_L1)!=0){
    Serial.println("L1 pressed");
    let();
  }
  else if(ps2x.Button(PSB_L2)!=0){
    Serial.println("L2 pressed");
    hold();
  }
  else if(ps2x.Button(PSB_L1)==0 || ps2x.Button(PSB_L2)==0){
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////
  if(ps2x.Button(PSB_PINK)!=0){
    Serial.println("square pressed");
    curve_down();
  }
  else if(ps2x.Button(PSB_RED)!=0){
    Serial.println("o pressed");
    curve_up();
  }
  else if(ps2x.Button(PSB_PINK)==0 || ps2x.Button(PSB_RED)==0){
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////
  if(ps2x.Analog(PSS_LX)||ps2x.Analog(PSS_LY))
  {
    Serial.print(ps2x.Analog(PSS_LX),DEC);
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_LY),DEC);
    delay(50); 
    if(ps2x.Analog(PSS_LY)<127){
      forward_car();
    }
    else if(ps2x.Analog(PSS_LY)>127){
      backward_car();
    }
    else if(ps2x.Analog(PSS_LY)==127||ps2x.Analog(PSS_LX)==128){
      stop_car();
    }
   if(ps2x.Analog(PSS_LX)<128){
      Left_car();
    }
    else if(ps2x.Analog(PSS_LX)>128){
      Right_car();    
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////

 if(ps2x.Button(PSB_START)){
    Serial.println("START pressed");
    led_on();
  }
  if(ps2x.Button(PSB_SELECT)){
    Serial.println("SELECT pressed");
    led_off();
  }
  //////////////////////////////////////////////////////////////////////////////////////////


  //SLAVE arduino 
  */if(ps2x.Button(PSB_GREEN)!=0){
    Serial.println("T");
    myserial.println('T');
  }
  else if(ps2x.Button(PSB_BLUE)!=0){
    Serial.println("X");
    myserial.println('X');
  }
  ///////////////////////////////////////////////////////////////////////////////////////////
/*
  if(ps2x.Button(PSB_PAD_UP)!=0){
    Serial.println("UP pressed");
    myserial.println('U');
  }
  else if(ps2x.Button(PSB_PAD_DOWN)!=0){
    Serial.println("DOWN pressed");
    myserial.println('D');
  }
  ///////////////////////////////////////////////////////////////////////////////////////

  if(ps2x.Button(PSB_PAD_RIGHT)!=0){
    Serial.println("right pressed");
    myserial.println('R');
  }
  else if(ps2x.Button(PSB_PAD_LEFT)!=0){
    Serial.println("left pressed");
    myserial.println('L');
  }
  /////////////////////////////////////////////////////////////////////////////////////

  if(ps2x.Button(PSB_R1)!=0){
    Serial.println("R1 pressed");
    myserial.println('S');
  }
  ///////////////////////////////////////////////////////////////////////////////////
  delay(10);// for delay(WoooooooW)
*/
}