#include <AFMotor.h>
AF_DCMotor front_left_motor(1);
AF_DCMotor back_left_motor(2);
AF_DCMotor front_right_motor(4);
AF_DCMotor back_right_motor(3);

#define SPEED 255

#define RXp2 17
#define TXp2 16

char incomingByte;
void stopMovement(){
	front_left_motor.run(RELEASE);
  back_left_motor.run(RELEASE);
	front_right_motor.run(RELEASE);
	back_right_motor.run(RELEASE);
}
void initMotors(){
	//Set initial speed of the motor & stop
	front_left_motor.setSpeed(SPEED);
  back_left_motor.setSpeed(SPEED);
	front_right_motor.setSpeed(SPEED);
	back_right_motor.setSpeed(SPEED);
	stopMovement();
}

void setup() {
  // put your setup code here, to run once:
  initMotors();
  Serial.begin(115200);
  Serial2.begin(9600);
}

void goForward(){
	front_left_motor.run(FORWARD);
  	back_left_motor.run(FORWARD);
	front_right_motor.run(FORWARD);
	back_right_motor.run(FORWARD);
}
void goBackward(){
	front_left_motor.run(BACKWARD);
  	back_left_motor.run(BACKWARD);
  	front_right_motor.run(BACKWARD);
  	back_right_motor.run(BACKWARD);
}
void goRight(){
	front_left_motor.run(FORWARD);
  	back_left_motor.run(FORWARD);
  	front_right_motor.run(BACKWARD);
  	back_right_motor.run(BACKWARD);
}
void goLeft(){
	front_left_motor.run(BACKWARD);
  	back_left_motor.run(BACKWARD);
  	front_right_motor.run(FORWARD);
  	back_right_motor.run(FORWARD);
}


void loop() {
  //  if (Serial2.available()>0)
  //  { 
    incomingByte=Serial2.read();
    // Serial.println(incomingByte);
    if(incomingByte=='U'){
      Serial.println("UP");
      goForward();
    }
    else if(incomingByte=='D'){
      Serial.println("DOWN");
      goBackward();
    }
    else if(incomingByte=='L'){
      Serial.println("LEFT");
      goLeft();
    }
    else if(incomingByte=='R'){
      Serial.println("RIGHT");
      goRight();
    }
    else if(incomingByte=='O'){
      Serial.println("STOP");
      stopMovement();
    }

}