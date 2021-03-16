#include <iostream>

struct Field
{
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard
{

  Field board [100][100];
  int width;
  int height;

public:
  
  MinesweeperBoard();
  int retWidth, retHeight;

  void setFrame(int * const &retWidth, int * const &retHeight);
  void debug_display()const;
};

//MinesweeperBoard::MinesweeperBoard(int width, int height) //pomocniczy konstruktor gdy użytkownik nie wprowadzi wielkości planszy
//{
//  if()
//}

MinesweeperBoard::MinesweeperBoard()
{

    for(int column = 0; column<height; column++) //do zmiany nazwa i, j
    {
      for(int row = 0; row<width; row++)
      {
        board[column][row].hasMine = false;
        board[column][row].hasFlag = false;
        board[column][row].isRevealed = false;
      }
    }

  //Do usuniecia później
  board[0][0].hasMine = true;
  board[1][1].isRevealed = true;
  board[2][0].hasMine = true;
  board[2][0].hasFlag = true;
}

void MinesweeperBoard::debug_display()const  
{
  for(int column = 0; column<height; column++)
    {
      for(int row = 0; row<width; row++)
      {
        std::cout << "[";
        if(board[column][row].hasMine) std::cout << "M";
        else std::cout << ".";
        if(board[column][row].isRevealed) std::cout << "o";
        else std::cout << ".";
        if(board[column][row].hasFlag) std::cout << "f";
        else std::cout << ".";
        std::cout << "]";
      }
      std::cout<<std::endl;
    }
}

void MinesweeperBoard::setFrame(int * const &retWidth, int * const &retHeight) //nie jestem pewien czy to tak powinno być 
  { 
    std::cout<<"Insert width & height: ";

    std::cin >> &retWidth >> &retHeight; 

  };

int main() 
{
  MinesweeperBoard mines;

  std::cout << "Łukasz Waszczak, 259625\n";
  
  mines.setFrame(&mines.retWidth, &mines.retHeight);

  mines.debug_display();

}