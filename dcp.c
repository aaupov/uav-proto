/*
 * Dispatcher Control Protocol realization.
 */

#include "dcp.h"
#include <stdlib.h>
#include <zlib.h>

struct msg_raw* cmd_handon()
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

struct msg_raw* cmd_handoff()
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



