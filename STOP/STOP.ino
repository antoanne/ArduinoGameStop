const int ledPinA =  9;
const int ledPinB =  10;
const int ledPinC =  11;
const int ledPinD =  12;
const int ledPinE =  13;

const int buttonPin = 2;

int currentLed = 0;
int currentDelay = 1000;

bool playing = true;

void setup() {
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);

  pinMode(buttonPin, INPUT);
  attachInterrupt(0,test,RISING);
}

void loop() {
  if(playing){
    onNext(); 
  }
}

void onNext(){
  delay(currentDelay);
  offAll();
  switch(currentLed) {
    case 0:
      digitalWrite(ledPinA, HIGH);
      break;
    case 1:
      digitalWrite(ledPinB, HIGH);
      break;
    case 2:
      digitalWrite(ledPinC, HIGH);
      break;
    case 3:
      digitalWrite(ledPinD, HIGH);
      break;
    default:
      digitalWrite(ledPinE, HIGH);
      break;
  }
  currentLed++;
  if(currentLed > 4){
    currentLed = 0;
  }
}

void offAll(){
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, LOW);
}

void onAll(){
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, HIGH);
  digitalWrite(ledPinC, HIGH);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
}

void test() {
  if(currentLed == 3) {
    hit();
  } else {
    miss();
  }
}

void hit() {
  playing = false;
  delay(3000);
  offAll();
  delay(1000);
  playing = true;
  currentDelay = currentDelay * 0.95;
}

void miss() {
  playing = false;
  onAll();
  delay(3000);
  offAll();
  delay(1000);
  currentLed = 0;
  playing = true;
  currentDelay = 1000;
}

