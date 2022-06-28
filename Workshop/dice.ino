const int diceLed[] = { 0b01000000, 0b00100100, 0b01100100, 0b00101101, 0b01101101, 0b00111111 };
volatile int diceNum;

void rollDice(){
  diceNum = random(0, 6);
}

void setup() {
  Serial.begin(9600);
  DDRF = 0xFF;
  randomSeed(analogRead(A0));
  diceNum = random(0, 6);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), rollDice, CHANGE);
}

void loop() {
  PORTF = diceLed[diceNum];
  Serial.println(diceNum + 1);
  delay(1000);
}

