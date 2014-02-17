/*
 * Dispatcher Control Protocol realization.
 */

#include "dcp.h"

struct msg_raw*
cmd_handon()
{
  struct msg_raw *buf;
  buf = malloc(sizeof(struct msg_raw));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_HandOn;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_raw*
cmd_handoff()
{
  struct msg_raw *buf;
  buf = malloc(sizeof(struct msg_raw));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_HandOff;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_heartbeat*
cmd_heartbeat(struct state st)
{
  struct msg_heartbeat* buf;
  buf = malloc(sizeof(struct msg_heartbeat));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_Heartbeat;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->st = st;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_reqconfirm*
cmd_reqconfirm(uint16_t cmdnum)
{
  struct msg_reqconfirm* buf;
  buf = malloc(sizeof(struct msg_reqconfirm));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_ReqConfirm;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->cmdnum = cmdnum;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_confirm*
cmd_confirm(uint16_t cmdnum, uint8_t status)
{
  struct msg_confirm* buf;
  buf = malloc(sizeof(struct msg_confirm));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_Confirm;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->cmdnum = cmdnum;
      buf->status = status;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_report*
cmd_report(uint16_t cmdnum, uint8_t report)
{
  struct msg_report* buf;
  buf = malloc(sizeof(struct msg_report));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_Report;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->cmdnum = cmdnum;
      buf->report = report;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_zerobaroalt*
cmd_zerobaroalt(uint16_t zerobaroalt)
{
  struct msg_zerobaroalt* buf;
  buf = malloc(sizeof(struct msg_zerobaroalt));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_ZeroBaroAlt;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->zerobaroalt = zerobaroalt;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_updcpt*
cmd_updcpd(uint16_t routenum, struct checkpoint pt)
{
  struct msg_updcpt *buf;
  buf = malloc(sizeof(struct msg_updcpt));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_UpdatePoint;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->routenum = routenum;
      buf->pt = pt;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_raw*
cmd_cleanroute()
{
  struct msg_raw *buf;
  buf = malloc(sizeof(struct msg_raw));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_CleanRoute;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_raw*
cmd_emergency()
{
  struct msg_raw *buf;
  buf = malloc(sizeof(struct msg_raw));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_Emergency;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}

struct msg_route*
cmd_route(uint16_t count, struct checkpoint *queue)
{
  struct msg_route *buf;
  buf = malloc(sizeof(struct message)+sizeof(uint16_t)+count*sizeof(struct checkpoint));
  if (buf)
    {
      buf->msg.proto = Proto_Dispatcher;
      buf->msg.type = Msg_NewRoute;
      buf->msg.num = new_msg_number(Proto_Dispatcher);
      buf->msg.checksum = 0;
      buf->count = count;
      memcpy(queue, buf->queue, count*sizeof(struct checkpoint));
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}
