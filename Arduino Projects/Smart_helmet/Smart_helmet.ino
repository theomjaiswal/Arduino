  int vs   = 2;
  int VCC  = 3;
  int sw1  = 4;
  int trig = 5;

void setup(){
 
  Serial.begin(9600);
  pinMode(VCC,  OUTPUT);
  pinMode(sw1,  OUTPUT);
  pinMode(trig, OUTPUT);
  digitalWrite(trig,HIGH);
  digitalWrite(VCC, HIGH);
  digitalWrite(trig ,LOW);
  delay(1000);
  digitalWrite(trig , HIGH);
  delay(3000);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  delay(3000);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  digitalWrite(sw1,LOW);
  delay(4000);
  digitalWrite(sw1,HIGH);
 
 
 
}
void loop(){
  long measurement = vibration();
  delay(50);
  Serial.println(measurement);
 
if(measurement > 5000){
    Serial.println("You have met with an Acciedent");
    digitalWrite(trig, LOW);
    delay(3000);
    digitalWrite(trig,  HIGH);
   }
else{
    digitalWrite(trig,HIGH);
 }
}
 long vibration(){
 long measurement = pulseIn(vs, HIGH);
 return measurement;
}
