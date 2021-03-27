#include "minesClass.h"
#include "MSBoardTextView.h"
#include <iostream> 
#include <time.h>

#ifndef MINESBOARD_H__ //test
#define MINESBOARD_H__ //test2

int main()
{
  MinesweeperBoard board(10, 10, GameMode::EASY);
  MSBoardTextView view( board ); //test2222
  GameState getGameState(GameState::RUNNING);

  board.debug_display();
  
  std::cout << "Łukasz Waszczak, 259625\n";
}

#endif