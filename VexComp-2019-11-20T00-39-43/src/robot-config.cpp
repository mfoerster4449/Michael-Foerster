#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;





// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeftMotor = motor(PORT1, ratio18_1, false);
motor frontRightMotor = motor(PORT2, ratio18_1, false);
motor backLeftMotor = motor(PORT3, ratio18_1, false);
motor backRightMotor = motor(PORT4, ratio18_1, false);

motor leftIntake = motor(PORT5, ratio18_1, false);
motor rightIntake = motor(PORT6, ratio18_1, false);

motor pushMotor = motor(PORT7, ratio18_1, false);




int rc_auto_loop_callback_Controller1() {
 frontLeftMotor.setVelocity(100, velocityUnits::pct);
 frontRightMotor.setVelocity(100, velocityUnits::pct);
 backLeftMotor.setVelocity(100, velocityUnits::pct);
 backRightMotor.setVelocity(100, velocityUnits::pct);

 leftIntake.setVelocity(100, velocityUnits::pct);
 rightIntake.setVelocity(100, velocityUnits::pct);

 pushMotor.setVelocity(100, velocityUnits::pct);


  while(true) {
    
    int32_t leftStick = Controller1.Axis3.value();
    if(leftStick > 0) {
      frontLeftMotor.spin(forward, 100, velocityUnits::pct);
      backLeftMotor.spin(forward, 100, velocityUnits::pct);
    }
    else if(leftStick < 0) {
      frontLeftMotor.spin(reverse, 100, velocityUnits::pct);
      backLeftMotor.spin(reverse, 100, velocityUnits::pct);
    }
    else {
      frontLeftMotor.stop();
      backLeftMotor.stop();
    }



    int32_t rightStick = Controller1.Axis2.value();
    if(rightStick > 0) {
      frontRightMotor.spin(reverse, 100, velocityUnits::pct);
      backRightMotor.spin(reverse, 100, velocityUnits::pct);
    }
    else if(rightStick < 0) {
      frontRightMotor.spin(forward, 100, velocityUnits::pct);
      backRightMotor.spin(forward, 100, velocityUnits::pct);
    }
    else {
      frontRightMotor.stop();
      backRightMotor.stop();
    }





    bool leftShoulder = Controller1.ButtonL1.pressing();
    bool leftTrigger = Controller1.ButtonL2.pressing();

    if(leftTrigger){
      leftIntake.spin(forward, 100, velocityUnits::pct);
      rightIntake.spin(reverse, 100, velocityUnits::pct);
    }
    else if(leftShoulder) { 
     leftIntake.spin(reverse, 100, velocityUnits::pct);
     rightIntake.spin(forward, 100, velocityUnits::pct);
    }
    else{
     leftIntake.stop();
     rightIntake.stop();


    bool rightShoulder = Controller1.ButtonR1.pressing();
    bool rightTrigger = Controller1.ButtonR2.pressing();

    if(rightTrigger){
      pushMotor.spin(reverse, 100, velocityUnits::pct);

    }
    else if(rightShoulder) { 
      pushMotor.spin(forward, 100, velocityUnits::pct);
    }
    else{
     pushMotor.stop();
    }

    }
  }
}
void vexcodeInit() {
}



