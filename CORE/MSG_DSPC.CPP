#include "./include/msg_dspc.h"

using namespace std;


MsgDispatch::MsgDispatch(unsigned short int in_capacity)
            : capacity(in_capacity)
 {
   total = 0;
   pstrMsg = new string [capacity];
 }


MsgDispatch::~MsgDispatch()
 {
   delete [] pstrMsg;
 }


void MsgDispatch::receive_message(char const * const in_msg)
 {
   if(total < capacity)
       pstrMsg[total++] = in_msg;
   else
     {
       for(unsigned short int i = 0; i < (capacity - 1); ++i)
           pstrMsg[i] = pstrMsg[i + 1];

       pstrMsg[capacity - 1] = in_msg;
     }
 }


void MsgDispatch::reset()
 {
   delete [] pstrMsg;

   total = 0;
   pstrMsg = new string [capacity];
 }


ostream & operator<<(ostream & out, MsgDispatch const & msg_d)
 {
   for(unsigned short int i = 0; i < msg_d.total; ++i)
       out << msg_d.pstrMsg[i] << endl;

   return out;
 }

