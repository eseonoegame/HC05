/**
 * @brief slave code for HC-05
 * @author Noé Game
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX   inverse en vrai
int message;					 // message reçu.
bool ready = false;

void setup()
{
	BTSerial.begin(38400); // Default communication rate of the console module
	Serial.begin(38400);   // Default communication rate of the Bluetooth module
	Serial.println("COUCOU");

	// pinMode(12, OUTPUT);
	// digitalWrite(12, HIGH);
	// delay(1000);

	// BTSerial.println("AT");
	// delay(1000);

	// BTSerial.println("AT+ROLE=0");
	// delay(1000);

	// BTSerial.println("AT+ADDR?");
	// delay(1000);

	// digitalWrite(2, LOW);
	delay(1000);
}


void loop()
{
	// //écoute des réponses des AT commandes.
	// while ((millis()-10000<0) and (ready == false))
	// {
	//   if (BTSerial.available() > 0)
	//   {
	//     Serial.write(BTSerial.read());
	//   }
	// }
	// ready = true;

	// Si message dans canal "BT" alors le print dans canal "console"
	if(BTSerial.available() > 0)
	{
		// message = BTSerial.read();
		// Serial.print("message reçu :: ");
		// Serial.println(message);
		Serial.write(BTSerial.read());
	}

	// si message dans canal "console" alors on le print dans le canal "BT"
	if(Serial.available() > 0)
	{
		BTSerial.write(Serial.read());
	}
}
