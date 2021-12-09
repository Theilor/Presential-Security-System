int pinoBuzzer = 8;
int pinoTrigger = 12;
int pinoEcho = 13;
void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoTrigger, OUTPUT);
  pinMode(pinoEcho, INPUT);
  Serial.begin(9600);
}
void loop() {
 
  digitalWrite(pinoTrigger, LOW);
  delayMicroseconds(2);
  
  
  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(10);
  
  
  digitalWrite(pinoTrigger, LOW);
  
  long duracaoAlto = pulseIn(pinoEcho, HIGH);
  
  long distancia = usParaCm(duracaoAlto); 
  
  if (distancia < 50){
    Serial.println(1);
    for (int x=0; x<5; x++){
      tone(pinoBuzzer,2000, 100);
      delay(2);
    delay(1000);
    }
  }
}

long usParaCm(long duracaoAlto) {
  
  long d = (duracaoAlto / 2) * .0343;
  
  return d;
  
}

