#include "getMines.h"
#include <iostream> 
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
  int width;
  int height;

  void getMines();

public:

  MinesweeperBoard(int width, int height, GameMode mode);

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  int countMines(int row, int col) const;

  bool hasFlag(int row, int col) const;

  void toggleFlag(int row, int col) const;

  void debug_display() const;
  
};

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
  //zerowanie flag i odkryc
  for (int column = 0; column < height; column++) 
  {
    for (int row = 0; row < width; row++)
    {
      board[column][row].hasFlag = false;
      board[column][row].isRevealed = false;
    }
  }
  
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
  MinesweeperBoard board(10, 10, GameMode::NORMAL);

  board.debug_display();

  std::cout << "Łukasz Waszczak, 259625\n";
}

#endif