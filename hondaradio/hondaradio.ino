int LED1 = 7;
int LED2 = 6;
int LED3 = 5;
int LED4 = 4;
int LED5 = 3;
int LED6 = 2;
#define RADIO 12
#define TAPE  11
#define PLAY  10
#define PREV  9
#define NEXT  8
#define BIN1  A1
#define BIN2  A2
#define BIN3  A3
#define BIN4  A4
#define BIN5  A5
#define BIN6  A6
#define CUTOFF 13

// mode 1 RADIO
// mode 2 TAPE
// mode 3 BLUETOOTH
int mode = 3;
int debounce = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(RADIO, OUTPUT);
  pinMode(TAPE, OUTPUT);
  pinMode(PLAY, OUTPUT);
  pinMode(PREV, OUTPUT);
  pinMode(NEXT, OUTPUT);
  pinMode(BIN1, INPUT_PULLUP);
  pinMode(BIN2, INPUT_PULLUP);
  pinMode(BIN3, INPUT_PULLUP);
  pinMode(BIN4, INPUT_PULLUP);
  pinMode(BIN5, INPUT_PULLUP);
  pinMode(BIN6, INPUT_PULLUP);
  pinMode(CUTOFF, OUTPUT);
  fillSweep();
  fillSweep();
  bluetooth();
}

void cutBTAudio() {
  digitalWrite(CUTOFF, LOW);
}

void connectBTAudio() {
  digitalWrite(CUTOFF, HIGH);
}

void ledsOff() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
}

void restoreMode() {
  if (mode == 1) {
    digitalWrite(LED1, HIGH);
  } else if (mode == 2) {
    digitalWrite(LED2, HIGH);
  } else if (mode == 3) {
    digitalWrite(LED3, HIGH);
  }
}

void flashLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(80);
  digitalWrite(pin, LOW);
  delay(10);
}

void sweepLeft() {
  ledsOff();
  for (int i = 2; i <= 7; i++) {
    flashLED(i);
  }
  restoreMode();
}

void sweepRight() {
  ledsOff();
  for (int i = 7; i >= 2; i--) {
    flashLED(i);
  }
  restoreMode();
}

void flashAll() {
  ledsOff();
  for (int i = 2; i <= 7; i++) {
    digitalWrite(i, HIGH);
  }
  delay(120);
  for(int i = 2; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  delay(80);
}

void flashAllThree() {
  for (int i = 0; i < 3; i++) {
    flashAll();
  }
  restoreMode();
}

void fillSweep() {
  digitalWrite(LED1, HIGH);
  delay(80);
  digitalWrite(LED2, HIGH);
  delay(80);
  digitalWrite(LED3, HIGH);
  delay(80);
  digitalWrite(LED4, HIGH);
  delay(80);
  digitalWrite(LED5, HIGH);
  delay(80);
  digitalWrite(LED6, HIGH);
  delay(80);
  digitalWrite(LED1, LOW);
  delay(80);
  digitalWrite(LED2, LOW);
  delay(80);
  digitalWrite(LED3, LOW);
  delay(80);
  digitalWrite(LED4, LOW);
  delay(80);
  digitalWrite(LED5, LOW);
  delay(80);
  digitalWrite(LED6, LOW);
  delay(80);
}

bool anyPressed() {
  if (digitalRead(BIN1) == LOW) { return true; }
  if (digitalRead(BIN2) == LOW) { return true; }
  if (digitalRead(BIN3) == LOW) { return true; }
  if (digitalRead(BIN4) == LOW) { return true; }
  if (digitalRead(BIN5) == LOW) { return true; }
  if (digitalRead(BIN6) == LOW) { return true; }
  return false;
}

void poll() {
  if (debounce == 1) {
    if (anyPressed() == false) {
      debounce = 0;
    } else {
      return;
    }
  }
  
  if (digitalRead(BIN1) == LOW) {
    debounce = 1;
    if (mode == 1) { return; }
    radio();
    return;
  }

  if (digitalRead(BIN2) == LOW) {
    debounce = 1;
    if (mode == 2) { return; }
    tape();
    return;
  }

  if (digitalRead(BIN3) == LOW) {
    debounce = 1;
    if (mode == 3) { return; }
    bluetooth();
    return;
  }

  if (digitalRead(BIN4) == LOW) {
    debounce = 1;
    if (mode != 3) { return; }
    previous();
    return;
  }

  if (digitalRead(BIN5) == LOW) {
    debounce = 1;
    if (mode != 3) { return; }
    playpause();
    return;
  }

  if (digitalRead(BIN6) == LOW) {
    debounce = 1;
    if (mode != 3) { return; }
    next();
    return;
  }
}

void radio() {
  cutBTAudio();
  digitalWrite(TAPE, LOW);
  ledsOff();
  delay(20);
  digitalWrite(RADIO, HIGH);
  digitalWrite(LED1, HIGH);
  mode = 1;
}

void tape() {
  cutBTAudio();
  digitalWrite(RADIO, LOW);
  ledsOff();
  delay(20);
  digitalWrite(TAPE, HIGH);
  digitalWrite(LED2, HIGH);
  mode = 2;
}

void bluetooth() {
  digitalWrite(RADIO, LOW);
  digitalWrite(TAPE, LOW);
  ledsOff();
  delay(20);
  digitalWrite(LED3, HIGH);
  connectBTAudio();
  mode = 3;
}

void previous() {
  digitalWrite(PREV, HIGH);
  delay(100);
  digitalWrite(PREV, LOW);
  sweepLeft();
}

void playpause() {
  digitalWrite(PLAY, HIGH);
  delay(100);
  digitalWrite(PLAY, LOW);
  flashAllThree();
}

void next() {
  digitalWrite(NEXT, HIGH);
  delay(100);
  digitalWrite(NEXT, LOW);
  sweepRight();
}

void loop() {
  // put your main code here, to run repeatedly:
  poll();
}
