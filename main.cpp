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

  void setFrame(int width,int height) //nie jestem pewien czy to tak powinno być 
  {
    std::cout<<"Insert width & height";

    std::cin >> width >> height; 
    
  };
  
public:
  
  MinesweeperBoard();
  
  void debug_display() const;
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
        board[i][j].hasMine = false;
        board[i][j].hasFlag = false;
        board[i][j].isRevealed = false;
      }
    }

}

void debug_display(int width, int height)
{
  Field a;

  for(int i = 0; i<height; i++)
    {
      for(int j = 0; j<width; j++)
      {
        std::cout << "[";
        if(a.hasMine) std::cout << "M.";
        else std::cout << ".";
        if(a.isRevealed) std::cout << "o.";
        else std::cout << ".";
        if(a.hasFlag) std::cout << "f";
        else std::cout << ".";
        std::cout << "]";
      }
      std::cout<<std::endl;
    }
}


int main() 
{
  Field field;
  MinesweeperBoard mines;

  std::cout << "Łukasz Waszczak, 259625\n";

  mines.debug_display();

}