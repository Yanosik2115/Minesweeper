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
  int width;
  int height;

public:
  MinesweeperBoard(int width, int height, GameMode mode);

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  int countMines(int row, int col) const;

  bool hasFlag(int row, int col) const;

  void toggleFlag(int row, int col) const;

  //void debug_display(int width, int height) const; zawiera się w konstruktorze
};

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
  srand(time(NULL));

  //odpowiednia ilosc min
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
  
  //zerowanie flag i odkryc
  for (int column = 0; column < height; column++) 
  {
    for (int row = 0; row < width; row++)
    {
      board[column][row].hasFlag = false;
      board[column][row].isRevealed = false;
    }
  }

  //wyswietlanie txt poprzednio debug_display
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

  std::cout << "Łukasz Waszczak, 259625\n";
}

#endif