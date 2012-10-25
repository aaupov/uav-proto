/*
 * Hand Control Protocol realization
 */

#include "hcp.h"
#include <stdlib.h>
#include <zlib.h>

struct msg_srvctl*
cmd_srvctl(struct servos srv)
{
  struct msg_srvctl *buf;
  buf = malloc(sizeof(struct msg_srvctl));
  if (buf)
    {
      buf->msg.proto = Proto_Hand;
      buf->msg.type = Msg_Srv;
      buf->msg.num = new_msg_number(Proto_Hand);
      buf->msg.checksum = 0;
      buf->srv = srv;
      buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
    }
  return buf;
}
  
