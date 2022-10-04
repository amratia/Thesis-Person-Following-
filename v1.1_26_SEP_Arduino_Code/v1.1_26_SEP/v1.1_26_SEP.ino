int amrInByte = 0;

int LED = 13;
/*
int ENA = 10;
int in1 = 9;
int in2 = 8; //  are LEFT
int in3 = 7;
int in4 = 6;
int ENB =  5; //  are RIGHT
*/

const int IN1 = 9;
const int IN2 =  8;
const int ENA =  10;

//int's for arduino motor shield (left)
const int IN3 = 7;
const int IN4 =  6;
const int ENB = 5;

int trigPin = 4;    // Trigger
int echoPin = 3;    // Echo
long duration, cm, dist;


//--------------------------------------------------------
void setup() {

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);

pinMode(LED, OUTPUT);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

Serial.begin(9600);
}
//--------------------------------------------------------
void loop() {
  dist = calc_dist();
  if(dist < 30){
    moveStop();
  }
  if (dist > 30){
    moveAccordingtoInByte();
  }
}
//--------------------------------------------------------
long calc_dist(void){ // retuns cm of type long
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  return cm;
}
//--------------------------------------------------------
void moveAccordingtoInByte(void){
  amrInByte = 0;
  if (Serial.available() > 0) {
          // read the incoming byte:
        amrInByte = int(Serial.read());
        if (amrInByte == 0){
          moveStop();
          delay(20);
        }
        if (amrInByte == 1){
          moveForward();
          delay(100);
        }
        if (amrInByte == 2){
          moveBackward();
          delay(100);
        }
        if (amrInByte == 3){
          moveRight();
          delay(100);
        }
        if (amrInByte == 4){
          moveLeft();
          delay(100);
        }
  }
}
//--------------------------------------------------------------- Movement New Kit
void moveForward(void)//decelares the forward() void
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB,100);
  analogWrite(ENA, 100);
}
//--------------------------------------------------------
void moveBackward(void)//decelares the forward() void
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100);
  analogWrite(ENA, 100);
  
}
//--------------------------------------------------------
void moveStop(void)//decelares the reverse() void
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);
  analogWrite(ENA, 255);
}
//--------------------------------------------------------
void moveRight(void)//decelares the turnright() void
{
  analogWrite(ENA, 50);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
  
}
//--------------------------------------------------------
void moveLeft(void)//decelares the turnleft() void
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); //wasLOW
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  analogWrite(ENA, 150);
}


//--------------------------------------------------------------- Movement Functions
/*
void moveForward(){
  analogWrite(ENA, 80);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(ENB, 80);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward(){
  analogWrite(ENA, 125);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(ENB, 125);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveStop(){
  analogWrite(ENA, 125);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  analogWrite(ENB, 125);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void moveRight(){
  analogWrite(ENA, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(ENB, 20);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveLeft(){
  analogWrite(ENA, 20);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(ENB, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
*/
//--------------------------------------------------------------- 
