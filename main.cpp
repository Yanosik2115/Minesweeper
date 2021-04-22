#include "minesClass.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <iostream> 
#include <time.h>

int main()
{
  MinesweeperBoard board(5, 5, GameMode::NORMAL);
  MSBoardTextView view( board ); //test2222
  MSTextController( board, view );
  
  board.debug_display();
  
  std::cout << "Łukasz Waszczak, 259625\n";
}
