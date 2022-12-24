  int vs  =  2;
  int gvc = 13;
  int c1  =  4;     
  int v1  =  7;
  
void setup(){
  Serial.begin(9600);
  pinMode(gvc,OUTPUT);
  digitalWrite(gvc,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(v1,HIGH);
  digitalWrite(c1,LOW);
  delay(1000);
  digitalWrite(c1,HIGH);
  delay(50);///////////////////////////////////////////////
  digitalWrite(v1,LOW);
  delay(3000);
  digitalWrite(v1,HIGH);
  delay(50);
}
void loop(){
  long measurement = vibration();
  delay(50);
  Serial.println(measurement);
 
if(measurement > 1000){
    Serial.println("You have met with an Acciedent");


   
   } 
else{

Serial.println("not now");
   
 }
}
 long vibration(){
 long measurement = pulseIn(vs, HIGH);
 return measurement;
}
