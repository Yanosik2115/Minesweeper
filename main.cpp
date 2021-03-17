#include <iostream> //test WSL
#include <time.h>

#ifndef MINESBOARD_H__
#define MINESBOARD_H__

enum GameMode
{
  DEBUG,
  EASY,
  NORMAL,
  HARD
};
enum GameState
{
  RUNNING,
  FINISHED_WIN,
  FINISHED_LOST
};
struct Field
{
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard
{

  Field board[100][100];
  int width = 5;
  int height = 5;

public:
  MinesweeperBoard(int width, int height, GameMode mode);
  MinesweeperBoard();
  //int *pWidth = &width;
  //int *pHeight = &height;

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  int countMines(int row, int col) const;

  bool hasFlag(int row, int col) const;

  void toggleFlag(int row, int col) const;

  void setFrame();
  void debug_display() const;
};

//MinesweeperBoard::MinesweeperBoard(int width, int height) //pomocniczy konstruktor gdy użytkownik nie wprowadzi wielkości planszy
//{
//  if()
//}

MinesweeperBoard::MinesweeperBoard()
{

  for (int column = 0; column < height; column++) //height i width błędy ale tylko w vscode
  {
    for (int row = 0; row < width; row++)
    {
      board[column][row].hasMine = false;
      board[column][row].hasFlag = false;
      board[column][row].isRevealed = false;
    }
  }

  //Do usuniecia później
  //board[0][0].hasMine = true;
  //board[1][1].isRevealed = true;
  //board[2][0].hasMine = true;
  //board[2][0].hasFlag = true;
}

void MinesweeperBoard::debug_display() const
{
  for (int column = 0; column < height; column++)
  {
    for (int row = 0; row < width; row++)
    {
      std::cout << "[";
      if (board[column][row].hasMine)
        std::cout << "M";
      else
        std::cout << ".";
      if (board[column][row].isRevealed)
        std::cout << "o";
      else
        std::cout << ".";
      if (board[column][row].hasFlag)
        std::cout << "f";
      else
        std::cout << ".";
      std::cout << "]";
    }
    std::cout << std::endl;
  }
}

void MinesweeperBoard::setFrame() //jakimś cudem działa (int *pWidth, int *pHeight)
{
  GameMode mode = HARD;

  srand(time(NULL));

  switch (mode)
  {
  case 1:
    EASY;

    for (int column = 0; column < height; column++)
    {
      for (int row = 0; row < width; row++)
      {
        int minePropability = RAND_MAX * 0.1;
        int num = rand();

        if (num <= minePropability)
        {
          board[column][row].hasMine = 1;
        }
        else
          board[column][row].hasMine = 0;
      }
    }

    break;
  case 2:
    NORMAL;

    for (int column = 0; column < height; column++)
    {
      for (int row = 0; row < width; row++)
      {
        int minePropability = RAND_MAX * 0.2;
        int num = rand();

        if (num <= minePropability)
        {
          board[column][row].hasMine = 1;
        }
        else
          board[column][row].hasMine = 0;
      }
    }

    break;
  case 3:
    HARD;

    for (int column = 0; column < height; column++)
    {
      for (int row = 0; row < width; row++)
      {
        int minePropability = RAND_MAX * 0.3;
        int num = rand();

        if (num <= minePropability)
        {
          board[column][row].hasMine = 1;
        }
        else
          board[column][row].hasMine = 0;
      }
    }

    break;
  case 4:
    DEBUG;



    break;
  default:

    break;
  }

  //std::cout<<"Insert width & height: ";

  //std::cin >> *pWidth >> *pHeight;
};

int MinesweeperBoard::getBoardWidth() const
{
  return width;
}

int MinesweeperBoard::getBoardHeight() const
{
  return height;
}

int MinesweeperBoard::getMineCount() const
{
  return 0;
}

int MinesweeperBoard::countMines(int row, int col) const
{
  return 0;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
  return 0;
}

void MinesweeperBoard::toggleFlag(int row, int col) const
{
}

int main()
{
  MinesweeperBoard mines;

  std::cout << "Łukasz Waszczak, 259625\n";

  mines.setFrame(); //(mines.pWidth. ,mines.pHeight)

  mines.debug_display();
}

#endif