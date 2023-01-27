#include <Servo.h>

Servo myServo;

String comStr = "";
int comInt=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // start serial port
  while(Serial.read()>=0){} // clear serial port's buffer
  
  myServo.attach(9); // attach myServo to GPIO_09
  myServo.writeMicroseconds(1000); // set initial PWM to minimal
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    // listen the Serial port, run the code when something catched..
    delay(10);
    comStr = Serial.readString(); // read out the string
    comInt = comStr.toInt(); // convert the string to integer
    comInt = constrain(comInt, 1000, 2000); // limit the integer between to 1000 and 2000

    Serial.println(comInt); // show the integer number on Serial Monitor
    myServo.writeMicroseconds(comInt); // write the integer number to Servo in unit of micro-second
    
  }
  
}
