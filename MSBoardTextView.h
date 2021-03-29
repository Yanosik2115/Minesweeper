#include "minesClass.h"
#include <iostream>

#ifndef MINESBOARDTX_H__
#define MINESBOARDTX_H__

/*struct MSStruct
{

};*/

class MSBoardTextView
{
    int height;
    int width;

    MinesweeperBoard playerBoard;

    MinesweeperBoard& playerBoardRef = playerBoard;

    MSBoardTextView *playerView;

    //MSBoardTextView& playerViewRef = playerView;


public:
    MSBoardTextView();
    
    MSBoardTextView(MinesweeperBoard& board);
    
    void display();
    //~MSBoardTextView();
};

#endif
