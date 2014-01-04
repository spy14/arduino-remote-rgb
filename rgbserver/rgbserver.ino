

#include <SPI.h>
#include <Ethernet.h>

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3



// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDA, 0x02 };
IPAddress ip(192,168,1,126); //<<< ENTER YOUR IP ADDRESS HERE!!!

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

String inString = "";    // string to hold input
int red=0, green=0, blue=0;
void setup()
{
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);
}

void loop() {
  // Read serial input:
  EthernetClient client = server.available();
  if (client) {
        while (client.connected()) {
      if (client.available()) {
    int inChar = client.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char 
      // and add it to the string:
      inString += (char)inChar; 
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      
      
      red = inString.toInt() / 1000000;
      green = inString.toInt() / 1000 % 1000;
      blue = inString.toInt() % 1000;
      
      analogWrite(REDPIN, red);
      analogWrite(BLUEPIN, blue);
      analogWrite(GREENPIN, green);
      
      // clear the string for new input:
      inString = ""; 
    }
   }
  }
 }
}


