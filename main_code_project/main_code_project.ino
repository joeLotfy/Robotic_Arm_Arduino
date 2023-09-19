/* 
1- data ------>13
2-command ------>12
3-vibration
4-gnd
5-3.3v
6-attention ------>A0
7-clock ------>11
8-desconsolad
9-acknokelage
*/

#define motor1_1 10
#define motor1_2 9

//#define motor2_1 10
//#define motor2_2 9

#define motor3_1 6
#define motor3_2 7

#define motor4_1 10
#define motor4_2 9

#define motor5_1 10
#define motor5_2 9

#define motor6_1 10
#define motor6_2 9

#define motor7_1 2  //  car right 
#define motor7_2 3  // car right

#define motor8_1 4  // car left
#define motor8_2 5  // car left

//#define pin1_speed 5
//#define pin1_speed 6

#define led A5


#include <PS2X_lib.h>
PS2X ps2x;
int error = 0;
byte vaibrate = 0;

//functions
//arm
void hold(){
  digitalWrite(motor1_1, HIGH);
  digitalWrite(motor1_2, LOW);
}

void let(){
  digitalWrite(motor1_1, LOW);
  digitalWrite(motor1_2, HIGH);
}
/////////////////////////////////////////////

void curve_up(){
  digitalWrite(motor2_1, HIGH);
  digitalWrite(motor2_2, LOW);
}

void curve_down(){
  digitalWrite(motor2_1, LOW);
  digitalWrite(motor2_2, HIGH);
} 
/////////////////////////////////////////////

void up(){
  digitalWrite(motor3_1, HIGH);
  digitalWrite(motor3_2, LOW);
}

void down(){
  digitalWrite(motor3_1, LOW);
  digitalWrite(motor3_2, HIGH);
}
/////////////////////////////////////////////
 
void forward(){
  digitalWrite(motor4_1, HIGH);
  digitalWrite(motor4_2, LOW);
}

void backward(){
  digitalWrite(motor4_1, LOW);
  digitalWrite(motor4_2, HIGH);
}
/////////////////////////////////////////////

void right(){
  digitalWrite(motor5_1, HIGH);
  digitalWrite(motor5_2, LOW);
}

void left(){
  digitalWrite(motor5_1, LOW);
  digitalWrite(motor5_2, HIGH);
}
/////////////////////////////////////////////

void spray_on(){
  digitalWrite(motor6_1, HIGH);
  digitalWrite(motor6_2, LOW);
}

void spray_off(){
  digitalWrite(motor6_1, LOW);
  digitalWrite(motor6_2, HIGH);
}
//////////////////////////////////////////

//car
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
}
////////////////////////////////////////////////

//led
void led_on(){
  digitalWrite(led, HIGH);
}

void led_off(){
  digitalWrite(led, LOW);
}
void setup(){
  Serial.begin(9600);
  error=ps2x.config_gamepad(11,12,A0,13,true,true);  //(clock,command,attention,data)
  if (error == 0){ 
    Serial.println("configration done!!");
  }
  else{
    Serial.println("error");
  }

  pinMode(motor1_1, OUTPUT);        
  pinMode(motor1_2, OUTPUT);  


  pinMode(motor2_1, OUTPUT);        
  pinMode(motor2_2, OUTPUT);

  pinMode(motor3_1, OUTPUT);        
  pinMode(motor3_2, OUTPUT);

  pinMode(motor4_1, OUTPUT);        
  pinMode(motor4_2, OUTPUT);

  pinMode(motor5_1, OUTPUT);
  pinMode(motor5_2, OUTPUT);


  pinMode(motor6_1, OUTPUT);
  pinMode(motor6_2, OUTPUT);

  //car
  pinMode(motor7_1, OUTPUT);
  pinMode(motor7_2, OUTPUT);
  pinMode(motor8_1, OUTPUT);        
  pinMode(motor8_2, OUTPUT);
  //pinMode(pin1_speed, OUTPUT);
  //pinMode(pin2_speed, OUTPUT);


  pinMode(led, OUTPUT);
}


void loop() {
  ps2x.read_gamepad(false,vaibrate); //vibrate all time
  
  // if cases 

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
/////////////////////////////////////////////

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
  /////////////////////////////////////////////

  if(ps2x.Button(PSB_GREEN)!=0){
    Serial.println("throw pressed");
    up();
  }
  else if(ps2x.Button(PSB_BLUE)!=0){
    Serial.println("x pressed");
    down();
  }
  else if(ps2x.Button(PSB_GREEN)==0 || ps2x.Button(PSB_BLUE)==0){
    digitalWrite(motor3_1, LOW);
    digitalWrite(motor3_2, LOW);
  }
  ////////////////////////////////////////////////////////

  if(ps2x.Button(PSB_PAD_UP)!=0){
    Serial.println("UP pressed");
    forward();
  }
  else if(ps2x.Button(PSB_PAD_DOWN)!=0){
    Serial.println("DOWN pressed");
    backward();
  }
  else if( (PSB_PAD_DOWN)==0 || ps2x.Button(PSB_PAD_UP)==0 ){
    digitalWrite(motor4_1, LOW);
    digitalWrite(motor4_2, LOW);
  }
  /////////////////////////////////////////////

  if(ps2x.Button(PSB_PAD_RIGHT)!=0){
    Serial.println("right pressed");
    right();
  }
  else if(ps2x.Button(PSB_PAD_LEFT)!=0){
    Serial.println("left pressed");
    left();
  }
  else if( (PSB_PAD_RIGHT)==0 || ps2x.Button(PSB_PAD_LEFT)==0 ){
    digitalWrite(motor5_1, LOW);
    digitalWrite(motor5_2, LOW);
  }
  //////////////////////////////////////////////////////////

  if(ps2x.Button(PSB_R1)!=0){
    Serial.println("R1 pressed");
    spray_on();
  }
  else if(ps2x.Button(PSB_R2)!=0){
    Serial.println("R2 pressed");
    spray_off();
  }
  else if( (PSB_R1)==0 || ps2x.Button(PSB_R2)==0 ){
    digitalWrite(motor6_1, LOW);
    digitalWrite(motor6_2, LOW);
  }
  /////////////////////////////////////////////

  if(ps2x.Analog(PSS_LX)||ps2x.Analog(PSS_LY)){
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
  /////////////////////////////////////////////////////////////////////

  if(ps2x.Button(PSB_START)){
    Serial.println("START pressed");
    led_on();
  }
  if(ps2x.Button(PSB_SELECT)){
    Serial.println("SELECT pressed");
    led_off();
  }
  /////////////////////////////////////////////

  if(ps2x.Button(PSB_L3)){
    Serial.println("L3 pressed");
  }
  if(ps2x.Button(PSB_R3)){
    Serial.println("R3 pressed");  
  }
 
delay(30);
}
