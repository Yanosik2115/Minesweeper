#include <iostream>

#ifndef MINESBOARD_H__
#define MINESBOARD_H__

void MinesweeperBoard::getMines() 
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
#endif