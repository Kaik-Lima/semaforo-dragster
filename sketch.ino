const int ledPins[] = {17, 16, 4, 2, 15};
const int estagio[] = {18, 0, 5, 19};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const int numEstagio = sizeof(estagio) / sizeof(estagio[0]); 
const int esperaEstagio = 300;
const int esperaCircuito = 400;

void setup() {
  for(int i = 0; i < numEstagio; i++){
    pinMode(estagio[i], OUTPUT);
    delay(esperaEstagio);
    digitalWrite(estagio[i], HIGH);
    delay(esperaEstagio);
  }

  pinMode(ledPins[0], OUTPUT);
  digitalWrite(ledPins[0], HIGH);
  delay(esperaCircuito);
   for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  for(int i = 0; i < numLeds - 2; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(esperaCircuito);
    digitalWrite(ledPins[i], LOW);
    //delay(esperaCircuito);
  }
  delay(esperaCircuito);
  digitalWrite(ledPins[3], HIGH);
  for (int i = 0; i < numEstagio; i++){
    digitalWrite(estagio[i], LOW);
  }
}

void loop() {

}
