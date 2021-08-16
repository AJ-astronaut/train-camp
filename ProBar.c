#include "ProBar.h"


void process_Bar()
{
   char Bar[Mun];
   memset(Bar,'\0',sizeof(Bar));
   const char *lable1="|/-\\";
   char lable2[4]={'|','/','-','\\'};
   int i=0;
   while(i<=100)
   {
      printf("load:[%-101s][%-3d%%][%c]\r", Bar,i,lable1[i%4]);
          fflush(stdout);
      //printf("\n");
      
      printf("[%-101s][%-3d%%][%c]\r", Bar,i,lable2[i%4]);
          fflush(stdout);
       Bar[i++]='#';
        
       usleep(3000);

   }

   printf("\n");
    



}
