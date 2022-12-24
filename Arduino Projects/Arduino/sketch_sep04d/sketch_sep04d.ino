void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("L1-");
  Serial.print(analogRead(A0));
  Serial.print("  L2-");
  Serial.print(analogRead(A1));
  
  Serial.print("      R1-");
  Serial.print(analogRead(A2));
  Serial.print("  R2");
  Serial.println(analogRead(A3));
  
  delay(50);
}
