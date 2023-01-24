#include <Servo.h>

/* This code is meant to control one servo from one pin 
 * on the joystick. This is for simplicity and for those
 * who only have one servo from their beta kit.
 */
const int jystk_y_pin = A1;
int jystk_y_cur_val;
const int jystk_y_max_val = 1023;
const int jystk_y_min_val = 0;

const int jystk_button_pin = 2;
int jystk_button_state;

const int led_1_pin = 3;

Servo servo_1; 
const int servo_1_pin = 10;
int servo_1_cur_val; 
const int servo_1_max_val = 180;
const int servo_1_min_val = 0;
 

void setup() {
  Serial.begin(9600);
  pinMode(jystk_y_pin, INPUT);
  pinMode(jystk_button_pin,INPUT);
  pinMode(led_1_pin, OUTPUT);
  digitalWrite(jystk_button_pin, HIGH);
  /*Attach servo to a pin. Some Arduino models
   * you will only be able to use pins 9 & 10
   */
  servo_1.attach(servo_1_pin);
}

void loop() {
  
  
  jystk_y_cur_val = analogRead(jystk_y_pin);
  jystk_button_state= digitalRead(jystk_button_pin);  
  //The map function eliminates the need to do math.
  servo_1_cur_val = map(jystk_y_cur_val, jystk_y_min_val, jystk_y_max_val, servo_1_min_val, servo_1_max_val);     
  servo_1.write(servo_1_cur_val);                  
  delay(200); 

  //make an LED light up when joystick button is pushed
  if (jystk_button_state == 0){
    digitalWrite(led_1_pin, HIGH);
  }
  else{
    digitalWrite(led_1_pin, LOW);
  }

  //Print the vals to the serial monitor
  Serial.print("Joystick Y val: ");
  Serial.println(jystk_y_cur_val);
  Serial.print("Servo position:");
  Serial.println(servo_1_cur_val);
  Serial.print("Servo Button State:");
  Serial.println(jystk_button_state);
  
}
