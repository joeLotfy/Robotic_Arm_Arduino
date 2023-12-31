//الحمدلله
//RX (Reciver)
//SLAVE Arduino
/*
connections:
TX(12) with RX(11)
common ground
*/
#define motor3_1 2
#define motor3_2 3

#define motor4_1 4
#define motor4_2 5

#define motor5_1 6
#define motor5_2 7

#define motor6_1 8
#define motor6_2 9

#include <SoftwareSerial.h>
SoftwareSerial myserial(11,12);  //(RX,TX)


//FUNCTIONS
//motor3
void up() {
  digitalWrite(motor3_1, HIGH);
  digitalWrite(motor3_2, LOW);
}

void down() {
  digitalWrite(motor3_1, LOW);
  digitalWrite(motor3_2, HIGH);
}
/////////////////////////////////////////////////////////
//motor4
void forward() {
  digitalWrite(motor4_1, HIGH);
  digitalWrite(motor4_2, LOW);
}

void backward() {
  digitalWrite(motor4_1, LOW);
  digitalWrite(motor4_2, HIGH);
}
////////////////////////////////////////////////////

//motor5
void right() {
  digitalWrite(motor5_1, HIGH);
  digitalWrite(motor5_2, LOW);
}

void left() {
  digitalWrite(motor5_1, LOW);
  digitalWrite(motor5_2, HIGH);
}
/////////////////////////////////////////////////////

//motor6
void spray_on() {
  digitalWrite(motor6_1, HIGH);
  digitalWrite(motor6_2, LOW);
}

void spray_off() {
  digitalWrite(motor6_1, LOW);
  digitalWrite(motor6_2, HIGH);
}
/////////////////////////////////////////////////////////



void setup() {
  myserial.begin(4800);
  Serial.begin(9600);
  myserial.setTimeout(12); ////for delay


  //pin_modes
  pinMode(motor3_1, OUTPUT);        
  pinMode(motor3_2, OUTPUT);
  
  pinMode(motor4_1, OUTPUT);        
  pinMode(motor4_2, OUTPUT);

  pinMode(motor5_1, OUTPUT);
  pinMode(motor5_2, OUTPUT);


  pinMode(motor6_1, OUTPUT);
  pinMode(motor6_2, OUTPUT);
  
}

void loop() {
  if(myserial.available()) {
    char input=myserial.read(); 
    Serial.println(input);
    //motor3
    if(input=='T') {
      up();
      delay(15);
    }
    else if (input=='X') {
      down();
      delay(15);
    }    
    else {
      digitalWrite(motor3_1, LOW);
      digitalWrite(motor3_2, LOW);
    }
    ////////////////////////////////////////////////////////

    //motor4
    if(input=='U') {
      forward();
      delay(15);
    }
    else if(input=='D') {
      backward();
      delay(15);
    }
    else {
      digitalWrite(motor4_1, LOW);
      digitalWrite(motor4_2, LOW);
    }
    //////////////////////////////////////////////////////
    
    //motor5
    if(input=='R') {
      right();
      delay(15);
    }
    else if(input=='L') {
      left();
      delay(15);
    }
    else {
      digitalWrite(motor5_1, LOW);
      digitalWrite(motor5_2, LOW);
    }
    /////////////////////////////////////////////////////////////

    //motor6
    if(input=='S') {
      spray_on();
      delay(15);
    }
    else {
      digitalWrite(motor6_1, LOW);
      digitalWrite(motor6_2, LOW);
    }
      //delay(50);
  }
}


