#define echoPin2
#define trigPin3
int echoPin = 2;
int trigPin = 3;
long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
  
  void loop()
    //clears the trigPin condition
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(4);
    //clear the tripPin
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    //capturing the time duration for sound wave travel in Ms
     duration = pulseIn(echoPin, HIGH);
    distance= duration = 0.0976 * duration;
    Serial.print(distance);
    Serial.print("cm");
  }
  
