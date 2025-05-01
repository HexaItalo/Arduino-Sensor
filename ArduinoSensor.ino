const int sensorGas = A0;
const int limitGas = 500;
const int flamePin = 2;
const int ledGas = 3;
const int ledFlame = 4;
const int buzzer = 5;

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(ledGas, OUTPUT);
  pinMode(ledFlame, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void gasDectetor(){
  int gasRead = analogRead(sensorGas);

  if(gasRead >= limitGas) {
    Serial.println("Gás detectado! ⚠️");
    Serial.print("valor lido do MQ-09: ");
    Serial.println(gasRead);

    digitalWrite(buzzer, LOW);
    digitalWrite(ledGas, HIGH);
  } else {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledGas, LOW);
  }
}

void flameDectetor() {
  int flameRead = digitalRead(flamePin);
  Serial.println(flameRead);

  if(flameRead != 1){
    Serial.println("Fogo detectado! 🔥");
    Serial.print("Valor lido Flame: ");
    Serial.println(flameRead);

    digitalWrite(buzzer, LOW);
    digitalWrite(ledFlame, HIGH);
  } else {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledFlame, LOW);
  }
}

void loop(){
  gasDectetor();
  delay(200);
  flameDectetor();

  delay(1000);
}
