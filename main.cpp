#include "minesClass.h"
#include <iostream> 
#include <time.h>

//#ifndef MINESBOARD_H__
//#define MINESBOARD_H__

int main()
{
  MinesweeperBoard board(10, 10, GameMode::EASY);

  board.getMines();

  board.debug_display();

  board.getBoardWidth();
  board.getBoardHeight(); 
  bool hasFlag(int row, int col);
  board.getMineCount();
  int countMines(int row, int col);
  
  std::cout << "Łukasz Waszczak, 259625\n";
}

//#endif