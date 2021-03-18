#include "minesClass.h"
#include <iostream> 
#include <time.h>

//#ifndef MINESBOARD_H__
//#define MINESBOARD_H__

int main()
{
  MinesweeperBoard board(10, 10, GameMode::NORMAL);

  board.getMines(GameMode::NORMAL);

  board.debug_display();

  std::cout << "Łukasz Waszczak, 259625\n";
}

//#endif