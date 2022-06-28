void setup(){
  DDRD = 0xFF;
  PORTD = 0x01;
}

void loop(){
  for (int i = 0; i < 7; i++){
   delay(1000);
   PORTD <<= 1;
  }
  for (int i = 0; i < 7; i++){
   delay(1000);
   PORTD >>= 1;
  }
}