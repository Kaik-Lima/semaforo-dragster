#define button 13
#define leds 4
#define stop 15

int estagio[leds] = {23, 22, 21, 19};
int drag[leds] = {18, 16, 0, 2};

void setup() {
  for(int i = 0; i < leds; i++) {
    pinMode(estagio[i], OUTPUT);
    pinMode(drag[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
  pinMode(stop, OUTPUT);
}

void loop() {
  while (digitalRead(button) == HIGH){
    digitalWrite(stop, LOW);
    for (int i = 0; i < leds; i++) {
      digitalWrite(estagio[i], HIGH);
      delay(400);
    }
    for (int i = 0; i < leds; i++) {
      digitalWrite(drag[i], HIGH);
      delay(500);
      digitalWrite(drag[i], LOW);
      if (i == 3) {
        while (digitalRead(button) == HIGH) {
          digitalWrite(drag[i], HIGH);
          for(int i = 0; i < leds; i++) {
            digitalWrite(estagio[i], LOW);
          }
        }
      }
    }
  }
  while (digitalRead(button) == LOW) {
    for(int i = 0; i < leds; i++) {
      digitalWrite(estagio[i], LOW);
      digitalWrite(drag[i], LOW);
    }
    digitalWrite(stop, HIGH);
  }
  
}