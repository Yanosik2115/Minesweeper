#include "minesClass.h"
#include "MSBoardTextView.h"
#include <iostream>

class MSTextController
{

    int height;
    int width;

    MinesweeperBoard &playerBoardRef;

    MSBoardTextView &playerViewRef;

public:
    MSTextController(MinesweeperBoard &Board, MSBoardTextView &View);
    

    void play();
};
