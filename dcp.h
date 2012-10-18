#ifndef PLANE_CONTROL_STRUCTURES
#define PLANE_CONTROL_STRUCTURES

/* 
 * TODO: Authentication commands!
 * TODO: Enumerate more report types.
 * TODO: Typedef maybe?
 */

/* Platform independent types */
#include <inttypes.h>

/* --------------- Different constants --------------- */

enum msg_types
{
  // Messages to board
  Msg_NewRoute = 1,
  Msg_CleanRoute,
  Msg_UpdatePoint,
	Msg_Emergency,
	Msg_ctrl_hand,
  // Messages from board
  Msg_Heartbeat = 101,
	// Control messages
  Msg_ReqConfirm = 201,
  Msg_Confirm,
  Msg_Report,
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

/* --------------- Base structures --------------- */

struct message
{
	uint8_t type; 
	uint16_t num; 
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
	uint16_t servoch1;  
	uint16_t servoch2; 
	uint16_t servoch3; 
	uint16_t servoch4; 
	uint16_t servoch5; 
	uint16_t servoch6;

	uint16_t speed; // (in mps?)
	uint8_t status; 
	// Where and how should I put information about next checkpoint?
	// struct checkpoint cpt;
}

/* --------------- Message structures --------------- */
/* --------------- (1) Messages to board --------------- */

struct msg_route
{
	struct message msg;
	uint16_t count; // checkpoints quantity in route
	struct checkpoint queue[0]; // checkpoint pointer 
}

struct msg_updcpt // = update checkpoint
{
	struct message msg;
	uint16_t routenum; // ordinal number in route
	struct checkpoint pt;
}

struct msg_raw // raw command can be used for all purposes: emergency, clean route, hand control, power control.
{
	struct message msg;
}

// correction of relative barometric altitude
struct msg_zerobaroalt
{
	struct message msg;
	uint16_t zerobaroalt; 
}

/* --------------- (2) Messages from board --------------- */

struct msg_heartbeat
{
	struct message msg;
	struct state st;
}

/* --------------- (3) Control messages --------------- */

// Command confirmation
struct msg_confirm
{
	struct message msg;
	uint16_t cmdnum; // message number of command to confirm 
	uint8_t status; 
}

// Request of command confirmation 
struct msg_reqconfirm 
{
	struct message msg;
	uint16_t cmdnum; 
}

// Command report
struct msg_report
{
	struct message msg;
	uint16_t cmdnum;
	uint8_t report;
}

#endif


