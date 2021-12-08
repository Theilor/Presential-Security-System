
int pinoTrigger = 12;
int pinoEcho = 13;
void setup() {
  
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
    Serial.println(distancia);
  }
}

long usParaCm(long duracaoAlto) {
  
  long d = (duracaoAlto / 2) * .0343;
  
  return d;
  
}
