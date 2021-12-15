#include <AFMotor.h> // Uses addafruit custom library to control the motor shield
#include <Servo.h> //was for opening mechanism. did not work.

// Declaring motors for the motor shield
AF_DCMotor claw(1);
AF_DCMotor elbow(2);
AF_DCMotor arm(3);
AF_DCMotor base(4);




void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  
  //step 1: grap kcup
  grabCup();
  //step 2: move kcup
  moveCup();
  //step 3: reset to original position
  reset();
  //*/
}

/*  Function Name: reset()
 *  Description: This function performs step 3 of the robot movement which moves the OWI
 *  back to its original position so that it can be used again
 * 
 */
 void reset() {
  resetStepTwo();
  resetStepOne();
 }
 
/*  Function Name: moveCup()
 *  Description: This function performs step 2 of the robot movement which moves the kcup
 *  to the side where the opening for the kcup will be
 */
void moveCup() {
  //step 2
  //2a. move kcup into kmachine 
  baseL(3200);
  elbowup(400);    elbowdn(400);
  armdn(600);     elbowdn(400);
  armup(300);
  //elbowup(400);   armdn(300);   
  //elbowup(400);
  openc(1000);
}

/*  Function Name: grabCup()
 *  Description: This function performs step 1 of the robot movement which moves the OWI
 *  arm forward and grabs the kcup.
 */
void grabCup() {
  //1a. forward motion to go to kcup position            
  armdn(3000); 
  elbowup(1500);
  armdn(1300);
  elbowup(1500);
  armdn(700);
  //1b. forward motion to grab kcup
  delay(500);
  openc(1500); 
  elbowup(500);   armdn(500);
  elbowup(500);   armdn(350);
  elbowup(550);   armdn(300);
  elbowup(600);
  //1c. grab and lift kcup
  closec(1000);
  armup(600);
}

void resetStepOne() {
  delay(1000);
  //1d. reverse step 1b to get back into starting position
  elbowdn(5000);
  armup(5000); 
  closec(2000);
}

void resetStepTwo() {
  //2b. reverse 2a
  delay(1000);
  armup(1000);
  baseR(3000);
  elbowdn(500);   armup(500);
  elbowdn(500);   armup(350); 
}


void loop() { 
  
}

//Function created to control the robot. They used the adafruit library custom digital write functions
// The controls are based on a timer set up that allows the motor to run for a decided amount of time before being turned off

//Controls left shoulder up movement
void armup(int timeset){
arm.run(FORWARD);
arm.setSpeed(200);
delay(timeset);
arm.run(RELEASE);}

void armdn(int timeset){
arm.run(BACKWARD);
arm.setSpeed(200);
delay(timeset);
arm.run(RELEASE);}

void baseL(int timeset){
base.run(BACKWARD);
base.setSpeed(200);
delay(timeset);
base.run(RELEASE);}

void baseR(int timeset){
base.run(FORWARD);
base.setSpeed(200);
delay(timeset);
base.run(RELEASE);}

void openc(int timeset){
claw.run(BACKWARD);
claw.setSpeed(200);
delay(timeset);
claw.run(RELEASE);}

void closec(int timeset){
claw.run(FORWARD);
claw.setSpeed(200);
delay(timeset);
claw.run(RELEASE);}

void elbowdn(int timeset){
elbow.run(FORWARD);
elbow.setSpeed(200);
delay(timeset);
elbow.run(RELEASE);}

void elbowup(int timeset){
elbow.run(BACKWARD);
elbow.setSpeed(200);
delay(timeset);
elbow.run(RELEASE);}


//}



//Universal Stop
  void STOP(void){
    //Just sets the speed of all motors to zero
    elbow.run(RELEASE);
    claw.run(RELEASE);
    base.run(RELEASE);
    arm.run(RELEASE);


 /* base.setSpeed(0);
  elbow.setSpeed(0);
  arm.setSpeed(0);
  claw.setSpeed(0);*/
  delay(1000);
}
