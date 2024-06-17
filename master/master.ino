/**
 * @brief master code for HC-05
 * @author Noé Game
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
int message = 0;				 // message à envoyé.

void setup()
{
	BTSerial.begin(38400); // Default communication rate of the Bluetooth module
	Serial.begin(38400);   // Default communication rate of the console module
	Serial.println("COUCOU");

	// pinMode(12, OUTPUT);
	// digitalWrite(12, HIGH);

	// BTSerial.println("AT");
	// delay(1000);

	// AT+UART=38400,0,0
	//  delay(1000);

	// BTSerial.println("AT+ORGL"); // Reset factory
	// delay(1000);

	// BTSerial.println("AT+RMAAD"); // Supprimer les adresses enregistrées
	// delay(1000);

	// BTSerial.println("AT+ROLE=1"); // Mode Master
	// delay(1000);

	// BTSerial.println("AT+RESET"); // Reset le module
	// delay(1000);

	// BTSerial.println("AT+CMODE=0"); // Mode de connexion fixe
	// delay(1000);

	// BTSerial.println("AT+BIND=98D3,61,F5CEFF"); // Adresse correcte du module Slave
	// delay(1000);

	// BTSerial.println("AT+INIT"); // Initialiser le SPP (profil série)
	// delay(1000);

	delay(500);
	// digitalWrite(12, LOW);
	delay(500);
}

void loop()
{
	// Si message dans canal "BT" alors le print dans canal "console"
	if(BTSerial.available() > 0)
	{
		Serial.write(BTSerial.read());
	}

	// si message dans canal "console" alors on le print dans le canal "BT"
	if(Serial.available() > 0)
	{
		BTSerial.write(Serial.read());
	}
}
