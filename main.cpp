#include "minesClass.h"
#include "MSBoardTextView.h"
#include <iostream> 
#include <time.h>

#ifndef MINESBOARD_H__
#define MINESBOARD_H__

int main()
{
  MinesweeperBoard board(10, 10, GameMode::EASY);
  MSBoardTextView view( board );
  GameState getGameState(GameState::RUNNING);

  board.debug_display();
  
  std::cout << "Łukasz Waszczak, 259625\n";
}

#endif