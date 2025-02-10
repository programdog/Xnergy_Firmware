#include <stdio.h>
#include "data_structure.h"


while (true)
{
	if (receive_handshake_request()) //receive handshake request from robot MCU A
	{
		print("receive handshake request from robot MCU A");

		// Validate and respond to the handshake
		if (crc_check_handshake() == true)
		{
			send_handshake_response();
			print("handshake successful");

			while (robot is still charging) //start charging
			{
				//just an example, not a simple communication like this
				//base on RTOS would be better
				receive_charging_info(CHARGER, robot_id);
				send_charging_info(CHARGER, robot_id);
				delay_ms(50);
			}

			charger_complete_charging(CHARGER, robot_id); //charging complete
			print("charging complete");

			release_charger(CHARGER, robot_id);//release charger
			print("release complete");
		}
		else
		{
			print("handshake errpr");
		}
	}
}
