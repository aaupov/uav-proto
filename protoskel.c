/*
 * Plane protocol skeleton functions
 */

#include "protoskel.h"

uint32_t dcp_num = 0;
uint32_t hcp_num = 0;

uint32_t
new_msg_number(uint8_t protocol)
{
  /*
   * Input: protocol type;
   * Output: number of message in protocol;
   * Error: [0] No protocol found;
   */
  switch (protocol)
    {
    case Proto_Dispatcher:
      dcp_num++;
      return dcp_num;
    case Proto_Hand:
      hcp_num++;
      return hcp_num;
    default:
      return 0;
    }
}

static uint32_t 
simple_sum_hash(const uint8_t data, size_t datasize)
{
    uint32_t s_hash=0;
    uint32_t s_counter;
    for( s_counter=0; s_counter < datasize; s_counter++)
        s_hash += *(&data + s_counter);
    return s_hash;
}

/* don't try this at home */
uint32_t 
crc32(uint32_t prev, const Bytef* buf, uint32_t len)
{
    return simple_sum_hash(*buf, len);
}

