#ifndef HAND_CONTROL_PROTOCOL
#define HAND_CONTROL_PROTOCOL

/* Basement constantd and structures for all plane protocols */
#include "protoskel.h"

struct msg_srvctl // contains servosupplies position
{
	struct message msg;
	struct servos srv;
};

/* useful commands from DCP */

struct msg_raw; // for Msg_HandOff only
struct msg_heartbeat;
struct msg_confirm;
struct msg_reqconfirm;
struct msg_report;

#ifndef DISPATCHER_CONTROL_PROTOCOL
#include "dcp.h"
#endif

/* HCP functions */
struct msg_srvctl* cmd_srvctl(struct servos srv);

#endif


