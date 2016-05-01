// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define sensorPin 0
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

double alpha = 0.75;
int period = 50;
double change = 0.0;
double minval = 0.0;
int FADESPEED = 2;
int r, g, b;

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  
  // 
  static double oldValue = 0;
  static double oldChange = 0;
  static int count = 0;
  static double total = 0;
  
  int rawValue = analogRead (sensorPin);
  delay(2);
  double value = alpha * oldValue + (1 - alpha) * rawValue;
  total += value;
  count++;
  
  if (count == 50) {
    double averageValue = total / count;
//    Serial.println(averageValue);
    total = 0;
    count = 0;
    if (averageValue >= 500 && averageValue <= 650) {
      analogWrite(REDPIN, 0);
      analogWrite (BLUEPIN, 255);
    } else {
      analogWrite(REDPIN, 0);
      analogWrite(REDPIN, 255);
    }
  }
  
//  Serial.print (rawValue);
//  Serial.print (",");
//  Serial.println (value);
  
  oldValue = value;
  delay (period);

//  int HeartRate; //average bpm
//  for (HeartRate = 70; HeartRate< 100; HeartRate++) {
//
//    r = 255/30*HeartRate; 
//    b = 255 - 255/30*HeartRate;
//    
//    analogWrite(REDPIN, r);
//    analogWrite(BLUEPIN, b);
//    delay(100);
//  }
  

//  
//  // fade from blue to violet
//  for (r = 0; r < 256; r++) {
//    analogWrite(REDPIN, r);
//    delay(FADESPEED);
//  }
//  
//  // fade from violet to red
//  for (b = 255; b > 0; b--) {
//    analogWrite(BLUEPIN, b);
//    delay(FADESPEED);
//  }
//  
//  // fade from red to yellow
//  for (g = 0; g < 256; g++) {
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//  }
//  
//  // fade from yellow to green
//  for (r = 255; r > 0; r--) {
//    analogWrite(REDPIN, r);
//    delay(FADESPEED);
//  }
//  
//  // fade from green to teal
//  for (b = 0; b < 256; b++) {
//    analogWrite(BLUEPIN, b);
//    delay(FADESPEED);
//  }
//  
//  // fade from teal to blue
//  for (g = 255; g > 0; g--) {
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//  }
}

