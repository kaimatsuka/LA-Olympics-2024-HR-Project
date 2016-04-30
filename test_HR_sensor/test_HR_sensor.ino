// Pulse Monitor Test Script

int sensorPin = 0;
double alpha = 0.75;
int period = 50;
double change = 0.0;
double minval = 0.0;
int redpin = 9; // select the pin for the red LED
int greenpin = 10;// select the pin for the green LED
int bluepin = 11; // select the pin for the blue LED
int val;

/* 
 *  11 = R, 10 = G, 9 = B
 *  
 */


void setup() {
  // put your setup code here, to run once:
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:5
  static double oldValue = 0;
  static double oldChange = 0;
  static int count = 0;
  static double total = 0;
 
  int rawValue = analogRead (sensorPin);
  double value = alpha * oldValue + (1 - alpha) * rawValue;
  total += value;
  count++;
  if (count == 50) {
    double averageValue = total / count;
    Serial.println(averageValue);
    total = 0;
    count = 0;
    if (averageValue >= 500 && averageValue <= 650) {
      analogWrite(redpin, 0);
      analogWrite (bluepin, 255);
    } else {
      analogWrite(redpin, 0);
      analogWrite(redpin, 255);
    }
   }
//
//  Serial.print (rawValue);
//  Serial.print (",");
//  Serial.println (value);
  
//  for (val = 255; val> 0; val --)
//  {
  oldValue = value;
  delay (period);
}
