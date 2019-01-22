//ard gnd ----> ard REST Disconnect it 
//esp tx ----> ard rx(10) 
//esp rx ----> ard tx (11)
//esp vcc ----> ard 5v 
//esp ch_pd ----> ard 5v 
//esp gnd ----> ard gnd
//esp gpio0 ----> none
//esp gpio2 ----> none


#include <SoftwareSerial.h>
#define RX 10
#define TX 11

SoftwareSerial esp8266(RX,TX); 
 
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  pinMode(2,OUTPUT);
  
}
void loop() {

  if(checkCommand()){
        Serial.println("Done!!!!!!!!!!!");

    
    }

}

bool checkCommand(){
  
  String command = esp8266.readString();
  Serial.print(command);
  if(command.equalsIgnoreCase("toggle2LightBulb")){
    digitalWrite(2,!digitalRead(2));
    return true;
    }

    else{
      return false;
      }
  
  }
