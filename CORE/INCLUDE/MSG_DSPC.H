#ifndef MSG_DSPC_H
#define MSG_DSPC_H

/*
*/

#include <iostream>
#include <string>


class MsgDispatch
 {
   friend ostream & operator<<(ostream & out, MsgDispatch const & msg_d);

   private:
           unsigned short int const capacity;
           unsigned short int       total;
           string                 * pstrMsg;

           MsgDispatch(MsgDispatch const & other);
           MsgDispatch & operator=(MsgDispatch const & other);

   public:
           MsgDispatch(unsigned short int const in_capacity);
           ~MsgDispatch();

           void receive_message(char const * const in_msg);
           void get_messages(char ** const ppch,
                             unsigned short int str_len) const;
           void reset();
 };


/*
*/

#endif

