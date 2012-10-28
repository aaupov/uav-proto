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
