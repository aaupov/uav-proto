#ifndef PLANE_CONTROL_STRUCTURES
#define PLANE_CONTROL_STRUCTURES

/* 
 * TODO: Authentication commands!
 * TODO: Enumerate more report types.
 * TODO:
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
  Msg_UpdateEdge,
	Msg_Emergency,
	Msg_ctrl_XBee,
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
  Re_None = 1
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
  Den_FlyControl = 2,
  Den_RouteDiff = 3 // route diffraction
}

/* Confirmation Status types */
enum confirm_type 
{
  Confirm_Verify = 1, // verification of confirmation
  Confirm_Cancel = 2, // cancellation of confirmation
  Confirm_ReqReport = 3 // request for report
}

/* --------------- Base structures --------------- */

struct message
{
	uint8_t type; 
	uint16_t num; 
	uint32_t checksum;	
}

struct checkpoint
{
	uint16_t id;
	float longitude; 
	float latitude;
}

struct emergpoint // emergency point
{
	uint16_t id;
	float longitude;
	float latitude;
}

struct edge
{
	uint16_t id;
	uint16_t id_cpt1; // identifier of checkpoint 1
	uint16_t id_cpt2; // identifier of checkpoint 2
	uint16_t speed;
	uint16_t altitude;
}

struct routedge // = route edge
{
	uint16_t edge_id; 
	struct routedge *prev; // previous edge
}

struct state
{
	uint8_t edge_id;
	uint8_t status; 

	float longitude; 
	float latitude; 
	float heading; 
	uint16_t baroalt; // barometric altitude 
	uint16_t gpsalt; // GPS altitude (in decs of cm)
	uint16_t temperature; // (in 0.01 degrees centigrade)
	uint16_t voltage; // (in 0.01 volts)
	uint16_t current; // (in 0.01 ampere)
	int boardtime; // (in seconds)
	uint8_t gsmlevel; 
	uint16_t last_msgnum; // last received message number
	uint8_t denial; 
	char handlregime; //Режим управления («ручное», «через СУ» ,«X-bee», «GSM»)
	uint16_t servoch1;  
	uint16_t servoch2; 
	uint16_t servoch3; 
	uint16_t servoch4; 
	uint16_t servoch5; 
	uint16_t servoch6;
}

/* --------------- Message structures --------------- */
/* --------------- (1) Messages to board --------------- */

struct msg_setroute
{
	struct message msg;
	unsigned short int lenght; // quantity of checkpoints
	uint16_t queue[]; // queue of checkpoints' identifiers
}

struct msg_cleanroute
{
	struct message msg;
}

struct msg_updcpt // = update checkpoint
{
	struct message msg;
	struct checkpoint pt;
}

struct msg_updedge // = update edge
{
	struct message msg;
	struct edge ed;
}

struct msg_raw // raw command can be used all purposes: emergency, hand control, X-Bee, power control
{
	struct message msg;
}

/* What is this command for? */
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


