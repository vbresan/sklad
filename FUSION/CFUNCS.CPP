#include "./include/cfuncs.h"


/* funkcije za opcenite operacije koje prethode kreiranju artikla
*/

char CHprocess_line(char     * line,
                    Article ** ppArt_new)
 { char * pchAmount,
  	* pchPrice,
        * pchName;
   unsigned short amount;
   double 	  price;
   char		  name[MAX_NAME_LENGHT + 1];
   char         * PCHcut_leading_whitespace(char * pchStr);
   unsigned short US_from_str(char * pchStr);
   Article      * PARTcreate_new_art(unsigned short amount,
                                     double price, char * name);

   /* razbij liniju na tri stringa
   */
   pchAmount = line;
   pchAmount = PCHcut_leading_whitespace(pchAmount);
   amount = US_from_str(pchAmount);
   if(!amount)
       return (F_ERR_AMOUNT);

   pchPrice = strpbrk(pchAmount, STR_BRK_SET);
   pchPrice = PCHcut_leading_whitespace(pchPrice);
   price = atof(pchPrice);
   if(!price)
       return (F_ERR_PRICE);

   pchName = strpbrk(pchPrice, STR_BRK_SET);
   pchName = PCHcut_leading_whitespace(pchName);
   strncpy(name, pchName, MAX_NAME_LENGHT);
   name[MAX_NAME_LENGHT] = '\0';
   pchName = strchr(name, '\0');
   pchName--;
   while(isspace(*pchName))
       *pchName-- = '\0';
   if(*name == '\0')
       return (F_ERR_NAME);

   *ppArt_new = PARTcreate_new_art(amount, price, name);
   if(*ppArt_new == NULL)
       return (F_ERR_CR_ART);
   else
       return (F_NO_ERR);
 }


unsigned short US_from_str(char * pchStr)
 { unsigned short ret_val;
   double	  tmp;

   tmp = atof(pchStr);
   if(tmp > USHRT_MAX)
       ret_val = 0;
   else
       ret_val = (unsigned short) tmp;

   return (ret_val);
 }


char * PCHcut_leading_whitespace(char * pchStr)
 {
   while(isspace(*pchStr) && (*pchStr != '\0'))
       pchStr++;

   return (pchStr);
 }


Article * PARTcreate_new_art(unsigned short amount,
                             double         price,
                             char 	  * name)
 { Article * tmpArticle;

   tmpArticle = new Article(price, name, amount);
   return (tmpArticle);
 }


