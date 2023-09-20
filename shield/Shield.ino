//لا حول ولا قوة ولا بالله
//L293d motor driver arduino shield
#include <PS2X_lib.h>
#include <AFMotor.h>

//define motors
//AF_DCMotor Motor1(1,MOTOR12_64KHZ);
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);



void setup() {
	Serial.begin(9600);
	//set speed 0~255
	Motor1.setSpeed(180);
	Motor2.setSpeed(180);
	Motor3.setSpeed(180);
	Motor4.setSpeed(180);
}

void loop() {
	//just keep forward for the sake of the test
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
