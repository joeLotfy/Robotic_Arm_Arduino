#define led 10
int i=0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if(ps2.start){
    if (i%2=0){ 
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, HIGH);
    i++;
    }
    else {
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, LOW);
    i++;
    }
  }
}
