#include "./include/article.h"
#include "./include/msg_dspc.h"
#include "./include/lstorage.h"
#include <iostream>


int main(int argc, char *argv[])
 { MsgDispatch     * pMsgDLStor;
   LoadableStorage * pLStor;
   Article         * pArt = new Article(3.3, "krepana lola");


   if(argc > 1)
       pLStor = new LoadableStorage(argv[1]);
   else
       pLStor = new LoadableStorage;

   cout << "Skladiste: " << endl;
   cout << *pLStor << endl;

   pLStor->add(pArt);

   cout << "Skladiste: " << endl;
   cout << *pLStor << endl;


   pMsgDLStor = &pLStor->MsgD;

   cout << *pMsgDLStor << endl;

   delete pLStor;

   return 0;
 }

