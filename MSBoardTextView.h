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
    MSBoardTextView();
    
    MSBoardTextView(MinesweeperBoard& board);

    void display();
    
};

#endif
