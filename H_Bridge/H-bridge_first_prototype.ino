// بسم الله الرحمن الرحيم
// تحت اشراف بشمهندس يوسف
// تم بحمد الله تعالي كتابة الكود التالي

#define speed1ena 5
#define speed2ena 6

#define motor1_1 10
#define motor1_2 11

#define motor2_1 1
#define motor2_2 2



void setup() {
  //input1 pin for motor 1
  pinMode(motor1_1, OUTPUT);        

  //input2 pin for motor 1
  pinMode(motor1_2, OUTPUT);    

  //analog output signal pin for motor 1
  pinMode(speed1ena, OUTPUT);
  analogWrite(speed1ena,120);  //can be from 0 to 255

}

void loop() {
  //motor 1 to rotate in a direction
  digitalWrite(motor1_1, HIGH);
  digitalWrite(motor1_2, LOW);
  delay(5000);

  //reverse the motor direction
  /*digitalWrite(motor1_1, LOW);
  digitalWrite(motor1_2, HIGH);
  delay(5000);
*/
 //analogWrite(9, 90);
}
