#ifndef PLANE_PROTOCOL_SKELETON
#define PLANE_PROTOCOL_SKELETON

/*
 * TODO: Enumerate more report types.
 */

/* Base constants */ 

enum protocols
{
	Proto_dispatcher = 1,
	Proto_hand
}

enum msg_dcp_types
{
	// Messages to board
	Msg_NewRoute = 1,
	Msg_CleanRoute,
	Msg_UpdatePoint,
	Msg_Emergency,
	Msg_HandOn,
	Msg_HandOff,
	// Messages from board
	Msg_Heartbeat = 51,
	// Control messages
	Msg_ReqConfirm = 101,
	Msg_Confirm,
	Msg_Report
}

enum msg_hcp_types
{
	Msg_srv = 1  
}  

enum report_types
{
	Re_OK = 0,
	Re_None
}

enum status_types
{
	Stat_FollowRoute = 1,
	Stat_Landing,
	Stat_Emergency,
	Stat_TakingOff,
	Stat_Spinning // spinning round a point
}

enum denial_types
{
	Den_Engine = 1,
	Den_FlyControl,
	Den_RouteDiff // route deviation
}

/* Confirmation Status types */
enum confirm_type 
{
	Confirm_Verify = 1, // verification of confirmation
	Confirm_Cancel, // cancellation of confirmation
	Confirm_ReqReport // request for report
}

/* Base structures */

struct message
{
	uint8_t proto; // protocol identifier
	uint8_t type; // command type identifier
	uint32_t num; // ordinal number of message
	uint32_t checksum;	
}

struct point
{
	float longitude; 
	float latitude;
}

struct checkpoint
{
	struct point position;
	struct point emergency;
	uint16_t speed;
	uint16_t altitude;
}

struct servos // servosupplies position
{
	uint16_t servoch1;  
	uint16_t servoch2; 
	uint16_t servoch3; 
	uint16_t servoch4; 
	uint16_t servoch5; 
	uint16_t servoch6;
}

struct state
{
	float longitude; 
	float latitude; 
	float heading; 
	uint16_t baroaltabs; // absolute barometric altitude
	uint16_t baroaltrel; // relative barometric altitude
	uint16_t gpsalt; // GPS altitude (in decs of cm)
	uint16_t temperature; // (in 0.01 degrees centigrade)
	uint16_t voltage; // (in 0.01 volts)
	uint16_t current; // (in 0.01 ampere)
	int boardtime; // (in seconds)
	uint8_t gsmlevel; 
	uint16_t last_msgnum; // last received message number
	uint8_t denial; 
	uint16_t gpsspeed; // (in km/h)
	uint16_t airspeed; // (in km/h)
	uint8_t status; 
	// Why do we need to send this information in heartbeat? Vitalii.
	struct servos srv;
	struct checkpoint cpt;
}

#endif
