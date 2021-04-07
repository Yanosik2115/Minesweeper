#include "minesClass.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <iostream> 
#include <time.h>

#ifndef MINESBOARD_H__ //test
#define MINESBOARD_H__ //test2

int main()
{
  MinesweeperBoard board(5, 5, GameMode::EASY);
  MSBoardTextView view( board ); //test2222
  MSTextController( board, view );
  
  board.debug_display();
  
  std::cout << "Łukasz Waszczak, 259625\n";
}

#endif