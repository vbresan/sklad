#include "./include/msg_dspc.h"
#include <cstring>

using namespace std;


void MsgDispatch::get_messages(char      ** const ppch,
                               unsigned short int str_len) const
 {
   for(unsigned short int i = 0; i < total; ++i)
     {
       strncpy(ppch[i], pstrMsg[i].c_str(), str_len);
       ppch[i][str_len + 1] = '\0';
     }
 }

