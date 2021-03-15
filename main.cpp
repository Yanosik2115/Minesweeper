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
  int setFrame();
  void debug_display()const;
};

//MinesweeperBoard::MinesweeperBoard(int width, int height) //pomocniczy konstruktor gdy użytkownik nie wprowadzi wielkości planszy
//{
//  if()
//}

MinesweeperBoard::MinesweeperBoard()
{

    for(int i = 0; i<height; i++)
    {
      for(int j = 0; j<width; j++)
      {
        board[i][j].hasMine = true;
        board[i][j].hasFlag = false;
        board[i][j].isRevealed = false;
      }
    }

  board[0][0].hasMine = true;
  board[1][1].isRevealed = true;
  board[2][0].hasMine = true;
  board[2][0].hasFlag = true;
}

void MinesweeperBoard::debug_display()const  
{
  for(int i = 0; i<height; i++)
    {
      for(int j = 0; j<width; j++)
      {
        std::cout << "[";
        if(board[i][j].hasMine) std::cout << "M";
        else std::cout << ".";
        if(board[i][j].isRevealed) std::cout << "o";
        else std::cout << ".";
        if(board[i][j].hasFlag) std::cout << "f";
        else std::cout << ".";
        std::cout << "]";
      }
      std::cout<<std::endl;
    }
}

int MinesweeperBoard::setFrame() //nie jestem pewien czy to tak powinno być 
  {
    std::cout<<"Insert width & height: ";

    std::cin >> width >> height; 
    
    return width, height;
  };

int main() 
{
  Field field;

  MinesweeperBoard mines;

  std::cout << "Łukasz Waszczak, 259625\n";
  
  mines.setFrame();

  mines.debug_display();

}