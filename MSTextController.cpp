#include "MSBoardTextView.h"
#include "minesClass.h"
#include "MSTextController.h"
#include <iostream>

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : playerBoardRef(board), playerViewRef(view)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSTextController::play()
{
    char ans;
    int x, y;

    if (playerBoardRef.getGameState() == RUNNING)
    {

        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1:To flag field type 'F'\n2:To reveal field 'R'\n3:To check mines around field type 'M'" << std::endl;
        std::cin >> ans;

        switch (ans)
        {
        case 1:
            'F';
            {
                std::cout << "Which field do you want to flag?";
                std::cin >> x >> y;
                if (playerBoardRef.hasFlag(x, y) == 1)
                    play();
                else
                    playerBoardRef.toggleFlag(x, y);
                play();
            }
        case 2:
            'R';
            {
                std::cout << "Which field do you want to reveal?";
                std::cin >> x >> y;
                playerBoardRef.revealField(x, y);
                play();
            }
        case 3:
            'M';
            {
                std::cout << "Which field do you want to check?";
                std::cin >> x >> y;
                std::cout << "There is: " << playerBoardRef.countMines(x, y) << " mines around";
                play();
            }
        case 4:
            default:
            {
                std::cout<<"Wrong input :<"<<std::endl;
            }
        }
    }
    else if (playerBoardRef.getGameState() == FINISHED_LOST)
    {
        std::cout << "You lost :<";
    }
    if (playerBoardRef.getGameState() == FINISHED_WIN)
    {
        std::cout << "You won :>";
    }
}