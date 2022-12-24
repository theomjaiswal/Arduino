#include <Wire.h>

int  X_out, Y_out, Z_out;

void setup() {
  Serial.begin(57600);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);

  X_out = ( Wire.read()<<8 | Wire.read() );
  Y_out = ( Wire.read()<<8 | Wire.read() );
  Z_out = ( Wire.read()<<8 | Wire.read() );

  Serial.print("X = ");
  Serial.print(X_out);
  Serial.print(" Y = ");
  Serial.print(Y_out);
  Serial.print(" Z = ");
  Serial.println(Z_out);


  delay(250);




  
}
