
//Inputs
#define bl_IN 1
#define stop_IN 2
#define horn_IN 3
#define joystick_IN A0
#define extraIn1 A3
#define extraIn2 5

//Outputs
#define bl_OUT 10
#define stop_OUT 7
#define horn_OUT 8
#define rl_OUT 9
#define joystick_OUT 6  
#define extraOut1 11
#define extraOut2 12

int runLightDefault = 0;
int aRead = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(bl_IN, INPUT);
  pinMode(stop_IN, INPUT);
  pinMode(horn_IN, INPUT);
  
  pinMode(bl_OUT, OUTPUT);
  pinMode(stop_OUT, OUTPUT);
  pinMode(horn_OUT, OUTPUT);
  pinMode(rl_OUT, OUTPUT);

  runLightDefault = analogRead(joystick_IN);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  checkBrakeLight();
  checkStop();
  checkHorn();
  checkRunLight();


}

void checkBrakeLight() {
  if (digitalRead(bl_IN) == HIGH) {
    digitalWrite(bl_OUT, HIGH);
  }
  else {
    digitalWrite(bl_OUT, LOW);
  }
}

void checkStop() {
  if (digitalRead(stop_IN) == HIGH) {
    digitalWrite(stop_OUT, HIGH);
    digitalWrite(bl_OUT, LOW);
    digitalWrite(horn_OUT, LOW);
    digitalWrite(rl_OUT, LOW);
    analogWrite(joystick_OUT, 0);
  }
  else {
    digitalWrite(stop_OUT, LOW);
    digitalWrite(bl_OUT, HIGH);
    digitalWrite(horn_OUT, HIGH);
    digitalWrite(rl_OUT, HIGH);
  }
}

void checkHorn() {
  if (digitalRead(horn_IN) == HIGH) {
    digitalWrite(horn_OUT, HIGH);
  }
  else {
    digitalWrite(horn_OUT, LOW);
  }
}

void checkRunLight() {
  aRead = analogRead(joystick_IN);
  if (aRead != runLightDefault) {
    digitalWrite(rl_OUT, HIGH);
  }
  else {
    digitalWrite(rl_OUT, LOW);
  }
  analogWrite(joystick_OUT, aRead); // joystick output equal to joystick input
}








