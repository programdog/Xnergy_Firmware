#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

//MCU A robot 
typedef struct ROBOT
{
	uint8_t id; //robot id
	uint8_t battery_percentage; //battery percentage
	uint8_t charging_status; //robot charging status
	uint8_t charger_id; //
} ROBOT;


//MCB B
typedef struct CHARGER
{
	uint8_t id; // charger id
	uint8_t battery_percentage; //robot battery percentage
	uint8_t charging_status; //free or not
	uint8_t robot_id; 
} CHARGER;

//hand shake
typedef struct HANDSHAKE
{
	uint8_t header[10];
	uint8_t payload[100];
	uint8_t crc;
} HANDSHAKE;

//exchange charging information
typedef struct CHARGING_INFO
{
	uint8_t header[10];
	uint8_t payload[50];
	uint8_t crc;
} CHARGING_INFO;



#endif