 #include<DS3231.h>
#include<String.h>
DS3231  rtc(SDA, SCL);
int relayPin=13;
byte inPin=2;
byte state=HIGH;
byte reading;
byte previous=LOW;
long time=0;
long debounce=200;
int sensorPin=A3;
int sensorValue=0;
int inputPin=4;
int c=0; 
int val;
float temp;
void setup() {
  pinMode(inPin,INPUT);
  pinMode(relayPin,OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
  rtc.begin();
   rtc.setDOW(FRIDAY);     // Set DOW-of-Week to SUNDAY
  rtc.setTime(10, 14, 00);     // Set the time to 12:00:00 (24hr format)
 rtc.setDate(15, 4, 2017);


}

void loop(){
  sensorValue = analogRead(sensorPin);
  Serial.print("The day of week is ");
Serial.println(rtc.getDOWStr());
  //Serial.print(" ");
  Serial.print("The temperature is ");
Serial.println(rtc.getTemp());
//Serial.print(" ");
Serial.print("Today's date is ");
   Serial.println(rtc.getDateStr());
  Serial.print("Time is ");

  Serial.println(rtc.getTimeStr());
  
 if(((!strcmp(rtc.getDOWStr(),"Monday"))||(!strcmp(rtc.getDOWStr(),"Tuesday"))||(!strcmp(rtc.getDOWStr(),"Wednesday"))||(!strcmp(rtc.getDOWStr(),"Thursday"))||(!strcmp(rtc.getDOWStr(),"Friday"))))
 {
  if(!strcmp(rtc.getTimeStr(),"10:14:15"))
  {
    state=HIGH;
  }
  if(!strcmp(rtc.getTimeStr(),"10:14:30"))
  {
    state=HIGH;
  }
  if(!strcmp(rtc.getTimeStr(),"10:14:45"))
  {
    state=HIGH;
  }
  
 }
  reading=digitalRead(inPin);
  if(reading==HIGH&&previous==LOW&&millis()-time>debounce)
  {
    if(state==LOW)
    state=HIGH;
    else
    state=LOW;

  time=millis();
  }
  digitalWrite(relayPin,state);
  previous=reading;
 if((!strcmp(rtc.getDOWStr(),"Saturday"))||(!strcmp(rtc.getDOWStr(),"Sunday")))
 {
  reading=digitalRead(inPin);
  if(reading==HIGH&&previous==LOW&&millis()-time>debounce)
  {
    if(state==LOW)
    state=HIGH;
    else
    state=LOW;

  time=millis();
  }
  digitalWrite(relayPin,state);
  previous=reading;
  
 }
 
  if (sensorValue>700)
  {
    state=HIGH;
  }
   
   }
 
 
 
 

