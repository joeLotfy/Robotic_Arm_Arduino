//لا حول ولا قوة ولا بالله
#include <PS2X_lib.h>
#include <AFMotor.h>

//AF_DCMotor Motor1(1,MOTOR12_64KHZ);
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);



void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);
	Motor1.setSpeed(180);
	Motor2.setSpeed(180);
	Motor3.setSpeed(180);
	Motor4.setSpeed(180);
	

}

void loop() {
  // put your main code here, to run repeatedly:
	Motor1.run(FORWARD);
	Motor2.run(FORWARD);
	Motor3.run(FORWARD);
	Motor4.run(FORWARD);
	delay(5000);

	//Motor1.run(BRAKE);
	//Motor1.run(BACKWARD);
	//delay(5000)
	//Motor1.run(RELEASE);
}
