#include <stdio.h>
#include "data_structure.h"



while (true)
{
	if (check_battery_level()) //battery level is below threshold
	{
		print("robot needs charging");

		available_charger_id = search_available_charger(); //search an available charger

		if (available_charger_id != false)
		{
			print("find an available charger");

			move_to_charger(available_charger_id); //move to charger

			success = handshake(ROBOT, available_charger_id); //send handshake request

			if (success == true)
			{
				print("handshake success");

				while (battery level < 99%)
				{
					//just an example, not a simple communication like this
					//base on RTOS would be better
					send_charging_info(ROBOT, available_charger_id);
					receive_charging_info(ROBOT, available_charger_id);
					delay_ms(50);
				}
				robot_complete_charging(ROBOT, available_charger_id); //charging complete
				print("charging complete");

				send_release_charger_command(ROBOT, available_charger_id);//release charger
				print("release complete");
			}
		}
		else
		{
			print("no available charger found");
		}
	}
}
