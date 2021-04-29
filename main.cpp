#include "minesClass.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <iostream> 
#include <time.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
  MinesweeperBoard board(5, 5, GameMode::NORMAL);
  MSBoardTextView view( board ); //test2222
  MSTextController( board, view );

  //SFML-owy smietnik

  MSSFMLView SFMLView (board);

  SFMLView.draw();

  board.debug_display();
  
  std::cout << "Łukasz Waszczak, 259625\n";
}
