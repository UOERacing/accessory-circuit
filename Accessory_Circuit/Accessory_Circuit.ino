
//Inputs
#define bl_IN 4         //pin 4 works
#define stop_IN 3
#define horn_IN 2      //pin 2 works
#define joystick_IN A0  //A0 works
#define estop_IN 5     //pin 5 works
#define extraIn2 1

//Outputs
#define bl_OUT 11     //pin 11 works
#define horn_OUT 8    //pin 8 works
#define rl_OUT 12     //pin 12 works, questionable
#define joystick_OUT 9  
#define estop_OUT 6   //pin 6 works
#define extraOut2 10

int runLightDefault = 0;
int aRead = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(bl_IN, INPUT_PULLUP);
  pinMode(estop_IN, INPUT_PULLUP);
  pinMode(stop_IN, INPUT_PULLUP);
  pinMode(horn_IN, INPUT_PULLUP);
  
  pinMode(bl_OUT, OUTPUT);
  pinMode(estop_OUT, OUTPUT);
  pinMode(horn_OUT, OUTPUT);
  pinMode(rl_OUT, OUTPUT);

  runLightDefault = analogRead(joystick_IN);
  Serial.begin(9600);
  digitalWrite(bl_OUT, LOW);
  digitalWrite(horn_OUT, LOW);
  digitalWrite(rl_OUT, LOW);
  digitalWrite(estop_OUT, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkBrakeLight();
  checkEstop();
  checkHorn();
  checkRunLight();
}

void checkBrakeLight() {
  if (digitalRead(bl_IN) == LOW) {
     digitalWrite(bl_OUT, LOW);
  }
  else {
    digitalWrite(bl_OUT, HIGH);
  }
}

void checkEstop() {
  if (digitalRead(estop_IN) == LOW) {
     digitalWrite(estop_OUT, LOW);
  }
  else {
    digitalWrite(estop_OUT, HIGH);
  }
}

void checkHorn() {
  if(digitalRead(horn_IN) == LOW) {
    digitalWrite(horn_OUT, LOW);
  }
  else if (digitalRead(horn_IN) == HIGH) {
    digitalWrite(horn_OUT, HIGH);
  }
}

void checkRunLight() {
  aRead = analogRead(joystick_IN);
  //Inverted Signals
  if (aRead != runLightDefault) {
    digitalWrite(rl_OUT, LOW);
  }
  else {
    digitalWrite(rl_OUT, HIGH);
  }
  analogWrite(joystick_OUT, aRead); // joystick output equal to joystick input
}




