#include "MSBoardTextView.h"
#include "minesClass.h"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board): height(board.getBoardHeight()), width(board.getBoardWidth())
{
    //board.hasFlag();
    
}

void MSBoardTextView::display()
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col <width; col++)
        {
            if(playerBoard.hasFlag(row, col))
            {
                
            }
        }
    }
}