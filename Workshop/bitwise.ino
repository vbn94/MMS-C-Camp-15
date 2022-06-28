#define SETBIT(reg,x) (reg |= (1 << (x)))
#define CLEARBIT(reg,x) (reg &= ~(1 << (x)))
#define CHANGEBIT(reg,x) (reg ^= (1 << (x)))
#define CHECKBIT(reg,x) (!!(reg & (1 << (x))))

void setup() {
  // output -> pin A2
  SETBIT(DDRF, 2);

  // input pull-up pin 2
  CLEARBIT(PORTE, 4);
  SETBIT(PORTE, 4);
}

void loop() {
  if (CHECKBIT(PINE, 4)){
    SETBIT(PORTF, 2);
  } else {
    CLEARBIT(PORTF, 2);
  }
  delay(100);
}