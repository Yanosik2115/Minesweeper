#include "minesClass.h"
#include "MSBoardTextView.h"
#include <iostream>

class MSTextController
{

int height;
int width;

MinesweeperBoard playerBoard;

MinesweeperBoard& playerBoardRef = playerBoard;

MSBoardTextView playerView;

MSBoardTextView& playerViewRef = playerView;

public:

    MSTextController(MinesweeperBoard& Board, MSBoardTextView& View);
    MSTextController();

    void play();

};

