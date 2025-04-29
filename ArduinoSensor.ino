const int sensorGas = A0;
const int limitGas = 500;
const int sensorFlame = A1;
const int limitFlame = 500;
const int ledGas = 2;
const int ledFlame = 3;
const int buzzer = 4;

void setup() {
  pinMode(ledGas, OUTPUT);
  pinMode(ledFlame, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void gasDetector(){
  int gasRead = analogRead(sensorGas);
  
  if(gasRead >= limitGas){
    Serial.println("Gás detectado! ⚠️");
    Serial.print("Valor lido MQ-09: ");
    Serial.println(gasRead);

    digitalWrite(buzzer, HIGH);
    digitalWrite(ledGas, HIGH);
    delay(3000);
  }else{
    digitalWrite(ledGas, LOW);
  }
}

void flameDectetor(){
  int flameRead = analogRead(sensorFlame);

  if(flameRead <= limitFlame){
    Serial.println("Fogo detectado! 🔥");
    Serial.print("Valor lido Flame: ");
    Serial.println(flameRead);

    digitalWrite(buzzer, HIGH);
    digitalWrite(ledFlame, HIGH);
    delay(3000) ;   
  }else{
    digitalWrite(ledFlame, LOW);
  }
}

void loop() {
  gasDetector();
  flameDectetor();  

  delay(3000);
}
