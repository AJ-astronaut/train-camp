#include"game.h"
int x=0;
int y=0;

void menu()
{

  printf("##############################\n");
  printf("##############################\n");
  printf("########Welcome  gobang#######\n");
  printf("##############################\n");
  printf("########1.PLAY   2.Exit#######\n");
  printf("##############################\n");
  printf("##############################\n");
  printf("Please input you select number:\n");

}
void ShowBoard(int board[ROW][COL],int row,int col)
{
  printf("\e[1;1H\e[2J");
  printf("  ");
  int i=0;
    for(;i<col;i++)
    {
     printf("%2d ",i);
    }
   printf("\n");
   
  for(i=0;i<row;i++)
  {
    printf("%2d",i);
    int j=0;
    for(;j<col;j++)
    {
       if(board[i][j] == 0)
           printf(" . ");
       else if(board[i][j] == PLAYER1)
         printf(" ● ");
       else 
         printf(" ○ ");
    }
    printf("\n");
    }
    }
void PLAYMove(int board[ROW][COL],int row,int col,int who)
{
  while(1)
  {
   printf("PLAYER[%d] enter you site:\n",who);
   scanf("%d %d",&x,&y);
  if(x<0||x>row-1||y<0||y>col-1)
  {
     printf("Site is no found,try again:\n");
     continue;
  }
  else if(board[x][y]!=0)
  {
     printf("Sorry!this site is Occupied!\n");
     continue;
  }
   else 
   {
    board[x][y] = who;
     break;
   }
}
}
int Chesscount(int board[ROW][COL],int row,int col,enum Dir d)
{
    int _x=x;
    int _y=y;
    int count =0;
    while(1)
    {
   switch(d)
   {
     case LEFT:
       _y--;
     break;
     case RIGHT:
       _y++;
     break;
     case UP:
      _x--;
     break;
     case DOWN:
      _x++;
      break;
     case LEFT_UP:
     _x--; _y--; 
     break;
     case LEFT_DOWN:
     _x++; _y--;
     break;
     case RIGHT_UP:
     _x--; _y++;
     break;
     case RIGHT_DOWN:
    _x++; _y++;
     default :
       break;
   }
if(board[x][y] == board[_x][_y])
{
  count++;
}
else 
  break;
}

return count;
}


int IsOver(int board[ROW][COL],int row,int col)
{
   int Count1=Chesscount(board,row,col,LEFT)+Chesscount(board,row,col,RIGHT)+1;
   int Count2=Chesscount(board,row,col,UP)+Chesscount(board,row,col,DOWN)+1;
   int Count3=Chesscount(board,row,col,LEFT_UP)+Chesscount(board,row,col,RIGHT_DOWN)+1;
   int Count4=Chesscount(board,row,col,LEFT_DOWN)+Chesscount(board,row,col,RIGHT_UP)+1;

   if(Count1 >= 5 || Count2 >= 5 || Count3 >= 5 || Count4 >= 5)
   {
      if(board[x][y] == PLAYER1)
      {
        return PLAYER1_WIN;
      }
      else 
      {return PLAYER2_WIN;

   }
   }
    int i=0;
   for(;i<row;i++)
   {
     int j=0;
      for(;j<col;j++)
      {
        if(board[i][j]==0)
        return NEXT;
      }
   }
    
    return DRAW;

}

void game()
{
  int board[ROW][COL];
  memset(board,0,sizeof(board));
  int result = NEXT;
  do
  {
    ShowBoard(board,ROW,COL);
    PLAYMove(board,ROW,COL,PLAYER1);
    result=IsOver(board,ROW,COL);
    if(NEXT != result)
    {break;}
    ShowBoard(board,ROW,COL);
    PLAYMove(board,ROW,COL,PLAYER2);
    result=IsOver(board,ROW,COL);
    if(NEXT != result)
    {break;}
  }while(1);


  switch(result)
  {
    case 1:
      printf("Congratulations to plarer1 on your victory!\n");
      break;
    case 2:
      printf("Congratulations to plarer2 on your victory!\n");
      break;
    case 3:
      printf("A draw,one more board,Please\n");
    default :
      break;
  }

  }

