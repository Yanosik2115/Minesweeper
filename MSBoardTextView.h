#include "minesClass.h"
#include <iostream>

#ifndef MINESBOARDTX_H__
#define MINESBOARDTX_H__

class MSBoardTextView
{
    int height;
    int width;

    MinesweeperBoard playerBoard;

    MinesweeperBoard& playerBoardRef = playerBoard;
    
public:

    MSBoardTextView(MinesweeperBoard& board);

    MSBoardTextView();

    void display();
    
};

#endif
