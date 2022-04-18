// SIT210-Task3.1P-WebHook
#include "Adafruit_DHT_Particle.h"
#define DHTPIN A2     // connected to pin analog0 

#define DHTTYPE DHT11		// DHT 11 

DHT dht(DHTPIN, DHTTYPE);
int led = D7;  // The on-board LED

void setup() {
  pinMode(led, OUTPUT);
  	Serial.begin(9600); 
	Serial.println("DHTxx test!");
    dht.begin();
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  float t = dht.getTempCelcius();
  if (isnan(t) || t==0 || t>60) { // check if the sensor reading is valid and abort if not, in this case I knew there wouldn't be any temp below 0 or above
	Serial.println("Failed to read from DHT sensor!");
	return;
	}
  String temp = String(t);
  Particle.publish("temp", temp, PRIVATE);
  delay(10000);               // Wait for 10 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(10000);               // Wait for 10 seconds
}



