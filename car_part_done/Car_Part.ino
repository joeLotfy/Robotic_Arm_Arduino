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

#include <PS2X_lib.h>
PS2X ps2x;
int error = 0;
byte vaibrate = 0;
//int led_count=0;

#define motor7_1 2  //  car right 
#define motor7_2 3  // car right

#define motor8_1 4  // car left
#define motor8_2 5  // car left

//#define pin1_speed 5
//#define pin1_speed 6



//functions
void backward_car(){
 	digitalWrite(motor7_1, LOW);  // right motor
	digitalWrite(motor7_2, HIGH);   // right motor
  	digitalWrite(motor8_1, HIGH);  // left motor
  	digitalWrite(motor8_2, LOW);  // left motor
}

void forward_car(){
  	digitalWrite(motor7_1, HIGH);   // right motor
  	digitalWrite(motor7_2, LOW);    // right motor
 	digitalWrite(motor8_1, LOW);
  	digitalWrite(motor8_2, HIGH);
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



void setup() {
    	Serial.begin(9600);
    
    	error=ps2x.config_gamepad(8,12,A0,13,true,true);  //(clock,command,attention,data)
    	if (error == 0){ 
      		Serial.println("configration done!!");
    	}
   	else{
     		Serial.println("error");
    	}

	pinMode(motor7_1, OUTPUT);
 	pinMode(motor7_2, OUTPUT);
	pinMode(motor8_1, OUTPUT);        
  	pinMode(motor8_2, OUTPUT);
}

void loop() {
  
	ps2x.read_gamepad(false,vaibrate);  

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
  	delay(30);
}
