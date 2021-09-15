#include<SPI.h>
// #include<nRF24L01.h>
#include<RF24.h>
RF24 radio(9, 10);
const byte address[6] = "00001";
float ans = 0;
void setup()
{
    Serial.begin(19200);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MAX);
    radio.stopListening();
}

void loop()
{
    ans = random(1, 10);
    Serial.println(ans); //Random number generator
    radio.write(&ans, sizeof(ans));
    delay(1000);
}