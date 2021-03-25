#include <iostream>

#ifndef MINESBOARDTX_H__
#define MINESBOARDTX_H__

struct MSStruct
{

};

class MSBoardTextView
{
    int height;
    int width;
    
    MinesweeperBoard& playerBoard;
    MSBoardTextView& playerView;


public:
    //MinesweeperBoard board;
    MSBoardTextView(MinesweeperBoard& board);
    
    void display();
    ~MSBoardTextView();
};

#endif