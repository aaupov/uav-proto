/*
 * Hand Control Protocol realization
 */

#include "hcp.h"
#include <stdlib.h>
#include <zlib.h>

uint32_t simple_sum_hash( uint8_t* data, size_t datasize)
{
    uint32_t s_hash = 0;
    uint32_t s_counter;
    for ( s_counter = 0; s_counter <  datasize; s_counter++)
    {
        s_hash += data[ s_counter ];
    }
    return s_hash;
}

struct msg_srvctl*
cmd_srvctl(struct servos srv)
{
  struct msg_srvctl *buf;
  buf = (struct msg_srvctl*)malloc(sizeof(struct msg_srvctl));
  if (buf)
    {
      buf->msg.proto = Proto_Hand;
      buf->msg.type = Msg_Srv;
      buf->msg.num = new_msg_number(Proto_Hand);
      buf->msg.checksum = 0;
      buf->srv = srv;
      //buf->msg.checksum = crc32(0, (Bytef*)&(buf), sizeof(buf));
      buf->msg.checksum = simple_sum_hash( ( uint8_t*)buf, sizeof( buf));
    }
  return buf;
}
  
