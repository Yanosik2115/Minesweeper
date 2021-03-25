#include <iostream>

#ifndef MINESBOARDTX_H__
#define MINESBOARDTX_H__

struct MSStruct
{

};

class MSBoardTextView
{
    
    
public:
    //MinesweeperBoard board;
    MSBoardTextView::MSBoardTextView(MinesweeperBoard& board);
    
    void display();
};

#endif