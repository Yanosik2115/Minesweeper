#include "MSBoardTextView.h"
#include "minesClass.h"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board): height(board.getBoardHeight()), width(board.getBoardWidth()),playerBoardRef(board)
{
    
}

void MSBoardTextView::display()
{
    GameState state = playerBoardRef.getGameState(); //nie zwraca stanu gry :<

    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col <width; col++)
        {
            char res = playerBoardRef.getFieldInfo(row, col);
            std::cout<<" ";

            if(&res == "x")
            {
                 std::cout <<"💣" ;
            }
            else if(&res == "F")
            {   
                std::cout<< "⛳";
            }
            else if(&res == "_") std::cout<<"🕳";
            else std::cout<<" ";
        }
    }
    std::cout<<std::endl;

    if(state == FINISHED_LOST) std::cout<<"YOU LOST";
    else if(state == FINISHED_WIN) std::cout<<"YOU WIN";
    else std::cout<<"STILL PLAYING";
}
