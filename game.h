#ifndef _GAME_H
#define _GAME_H

#include<stdio.h>
#include<string.h>



#define ROW 21
#define COL 21
#define PLAYER1 1
#define PLAYER2 2

#define NEXT 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 3
  void game();
  void menu(); 
enum Dir
{
  LEFT,
  RIGHT,
  UP,
  DOWN,
  LEFT_UP,
  LEFT_DOWN,
  RIGHT_UP,
  RIGHT_DOWN,
};

#endif
