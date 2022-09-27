int amrInByte = 0;

int LED = 13;

int ENA = 10;
int in1 = 9;
int in2 = 8; //  are LEFT
int in3 = 7;
int in4 = 6;
int ENB =  5; //  are RIGHT

void setup() {

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);

pinMode(LED, OUTPUT);

Serial.begin(9600);
}

void loop() {
amrInByte = 0;
if (Serial.available() > 0) {
          // read the incoming byte:
        amrInByte = int(Serial.read());
        if (amrInByte == 0){
          moveStop();
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

//--------------------------------------------------------------- Movement Functions
void moveForward(){
  analogWrite(ENA, 70);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(ENB, 70);
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
//--------------------------------------------------------------- 
