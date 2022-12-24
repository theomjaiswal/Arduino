#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h>

const uint64_t my_radio_pipe = 0xE8E8F0F0E1LL; 
RF24 radio(9, 10); 

struct Data_to_be_sent {
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
  byte ch8;

};

Data_to_be_sent sent_data;
void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(my_radio_pipe);

  sent_data.ch1 = 127;
  sent_data.ch2 = 127;
  sent_data.ch3 = 127;
  sent_data.ch4 = 127;
  sent_data.ch5 = 0;
  sent_data.ch6 = 0;
  sent_data.ch7 = 0;
  sent_data.ch8 = 0;

}

void loop()
{
  sent_data.ch1 = map( analogRead(A0), 5, 920, 0, 255);
  sent_data.ch2 = map( analogRead(A1), 1, 880, 0, 255);
  sent_data.ch3 = map( analogRead(A2), 0, 880, 0, 255);
  sent_data.ch4 = map( analogRead(A3), 0, 880, 0, 255);
  sent_data.ch5 = digitalRead(2);
  sent_data.ch6 = digitalRead(3);
  sent_data.ch7 = map( analogRead(A4), 0, 1024, 0, 255);
  sent_data.ch8 = map( analogRead(A5), 0, 1024, 255, 0);

  radio.write(&sent_data, sizeof(Data_to_be_sent));

  Serial.print("L1-");
  Serial.print(sent_data.ch1);
  Serial.print("   L2-");
  Serial.print(sent_data.ch2);
  Serial.print("   L3-");
  Serial.print(sent_data.ch6);
  Serial.print("   L4-");
  Serial.print(sent_data.ch8); 
  Serial.print("   R1-");
  Serial.print(sent_data.ch3);
  Serial.print("   R2-");
  Serial.print(sent_data.ch4);
  Serial.print("   R3-");
  Serial.print(sent_data.ch5);
  Serial.print("   R4-");
  Serial.println(sent_data.ch7);

  




  
}
