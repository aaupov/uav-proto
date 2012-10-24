/*
 * Plane protocol skeleton functions
 */

#include "protoskel.h"

uint32_t new_msg_number(uint8_t protocol)
{
  /*
   * Input: protocol type;
   * Output: number of message in protocol;
   * Error: [0] No protocol found;
   */
  uint32_t *num;
  switch (protocol)
    {
    case Proto_Dispatcher:
      num = &dcp_num;
      break;
    case Proto_Hand:
      num = &hcp_num;
      break;
    default:
      return 0;
    }
  (*num)++;
  return *num;
}
