#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <SPI.h>


// Setup Variables
int sig1 = 4; // the pins that will be used when the pixy cam picks up that specific signature.
int sig2 = 7;
int sig3 = 8;
Pixy pixy;


void setup()
{
  // I really need to pick up a better way to spend my saturday nights. That is just a true fact
  
Serial.begin(9600);
Serial.print("Starting Serial"); // this is to start the communication between the Arduino and the Pixy cam. Because they communicate through serial.
delay (200);

pinMode(sig1, OUTPUT); // So a signature can be perceived as an output.
pinMode(sig2, OUTPUT);
pinMode(sig3, OUTPUT);

pixy.init();
}
void loop() {
  // Very important code section
static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 

 blocks = pixy.getBlocks();

  if (blocks)
  {
    i++;
    // I just copied this and it worked
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
 
 if (pixy.blocks[j].signature == 1)       //if a pixy block is seen on the pixy it will tell the Arduino through the serial and depending on the signature of 1, 2, or 3 it will run the rest of the code down below turing their indivual pin through a cycle of high and low.
      
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
