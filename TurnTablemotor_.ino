
 /* This sketch demonstrates the Serial parseInt() function.
  It looks for an ASCII string of comma-separated values.
  It parses them into ints, and uses those to fade an RGB LED.
*/

#include <AFMotor.h>



AF_DCMotor motor1(4); 
//AF_DCMotor motor2(2);  //,MOTOR12_64KHZ);


int  Speed = 254;
int OnTime=5;
int offTime=30;
int Dir =0;

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(Speed);
  motor1.run(RELEASE);
  Dir=0;

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Enter Speed Ontime OffTime (direction 0 for Forward and 1 Backward) ");
}

    
void loop() {
  // put your main code here, to run repeatedly:

//motor1.setSpeed(121);
  if (Dir==0) 
 motor1.run(FORWARD); 
 else 
 motor1.run(BACKWARD);
  
    delay(OnTime);
   // delayMicroseconds(OnTime);

  // Now turn off motor
  motor1.run(RELEASE);
  delay(offTime);
  //delayMicroseconds(offTime);
 //Serial.println("Enter Speed Ontime OffTime ");

// if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
     Speed = Serial.parseInt();
    // do it again:
    OnTime = Serial.parseInt();
    // do it again:
    offTime = Serial.parseInt();
  // do it again:
    Dir = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
    
      motor1.setSpeed(Speed);

       // print the three numbers
      Serial.print("  Speed:") ;
      Serial.println(Speed) ;
      Serial.print(" OnTime:");
       Serial.println(OnTime);
      Serial.print("OffTime:");
       Serial.println(offTime);
      Serial.print("Direction:");
        if (Dir==0 )
          Serial.println("FORWARD"); 
       else 
          Serial.println("BACKWARD");
      Serial.println(" To Change Enter Speed Ontime OffTime Direction(0/1) ");
    }
        

 }


}
