#include <iostream> //test WSL

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
  int *pWidth = &width; 
  int *pHeight = &height;

  void setFrame(int *pWidth, int *pHeight);
  void debug_display()const;
};

//MinesweeperBoard::MinesweeperBoard(int width, int height) //pomocniczy konstruktor gdy użytkownik nie wprowadzi wielkości planszy
//{
//  if()
//}

MinesweeperBoard::MinesweeperBoard()  
{

    for(int column = 0; column<height; column++) //height i width błędy ale tylko w vscode
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

void MinesweeperBoard::setFrame(int *pWidth, int *pHeight) //jakimś cudem działa 
  { 
    
    std::cout<<"Insert width & height: ";

    std::cin >> *pWidth >> *pHeight; 

  };

int main() 
{
  MinesweeperBoard mines;

  std::cout << "Łukasz Waszczak, 259625\n";

  mines.setFrame(mines.pWidth, mines.pHeight);

  mines.debug_display();

}
