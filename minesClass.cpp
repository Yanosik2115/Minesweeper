#include "minesClass.h"

//#ifndef MINESBOARD_H__
//#define MINESBOARD_H__

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
  for (int column = 0; column < height; column++) 
  {
    for (int row = 0; row < width; row++)
    {
      board[column][row].hasFlag = false;
      board[column][row].isRevealed = false;
    }
  }
}

void MinesweeperBoard::getMines(GameMode mode)  
{
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
    
}
//int MinesweeperBoard::getBoardWidth() const;
//int MinesweeperBoard::getBoardHeight() const;
//int MinesweeperBoard::getMineCount() const;

//int MinesweeperBoard::countMines(int row, int col) const;

//bool MinesweeperBoard::hasFlag(int row, int col) const;

//void MinesweeperBoard::toggleFlag(int row, int col) const;

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

//#endif

