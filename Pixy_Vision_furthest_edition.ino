#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <SPI.h>


// Setup Variables
int sig1 = 4; // designations for when the specific signal is recieved, that specific pin will go high.
int sig2 = 7;
int sig3 = 8;
Pixy pixy;


void setup()
{
  // I really need to pick up a better way to spend my saturday nights.
Serial.begin(9600);
Serial.print("Initializing Sentience procedure ... Failed, like usual ;)");
delay (200);
Serial.print("Alright Fucker here you go, knock yourself out");
pinMode(sig1, OUTPUT); // so they are precieved as an output pin. real shocker there.
pinMode(sig2, OUTPUT);
pinMode(sig3, OUTPUT);

pixy.init();
}
void loop() {
  // The main God DAmn event! You better prepare yourself for the most mind blowing shit you have ever seen!
static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 

 blocks = pixy.getBlocks();

  if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
      }
 
 if (pixy.blocks[j].signature == 1)       
      
  { 
    digitalWrite(sig1, HIGH);
    delay(5000);
    digitalWrite(sig1, LOW);
  }
 else if (pixy.blocks[j].signature == 2)      
      
  { 
    digitalWrite(sig2, HIGH);
    delay(5000);
    digitalWrite(sig2, LOW);
  }
  else if (pixy.blocks[j].signature == 3)       
      
  { 
    digitalWrite(sig3, HIGH);
    delay(5000);
    digitalWrite(sig3, LOW);
  }
  

}
  }
}
