#include"game.h"
#include"ProBar.h"


int main()
{
  
  int q=0;
  int select=0;
  while(!q)
  {
  
    menu(); 
  scanf("%d",&select);
   switch(select)
   {
     case 1:
     process_Bar();
     game();
     break;

     case 2:     
    printf("Bye Bye  Welcome back next time\n" );
    q=1;
    break;

    default :
    printf("Enter error,please try again:\n");
    break;

   }

}
 return 0;

}
