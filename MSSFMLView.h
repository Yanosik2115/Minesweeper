//#include <SFML/Window.hpp>
#include "minesClass.h"
#include <iostream>
#include <SFML/Graphics.hpp>
class MSSFMLView
{

    int height;
    int width;
    MinesweeperBoard &playerBoardRef;
    GameMode mode;

    

public:

    MSSFMLView(MinesweeperBoard &board);

    void draw();
    
};