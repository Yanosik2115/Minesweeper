#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : height(board.getBoardHeight()), width(board.getBoardWidth()), playerBoardRef(board)
{
}

void MSSFMLView::draw()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "Saper");

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                break;
            default:
                break;
            }

            //obsluga innych eventow
        }

        win.clear(sf::Color(28, 128, 128));

        //tile shape

        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(50, 50));
        tile.setOutlineColor(sf::Color::Black);
        tile.setOutlineThickness(2);
        tile.setFillColor(sf::Color::White);

        //loop for board

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tile.setPosition(270 + j * 50, 200 + i * 50);
                win.draw(tile);
            }
        }

        //loop for leftClickOnTile
        /*if(event.MouseButtonPressed == sf::Mouse::Left && event.mouseButton.x > 270 && event.mouseButton.x < 320 && event.mouseButton.y <200 && event.mouseButton.x > 250)
        {
            tile.setFillColor(sf::Color::Red);
            tile.setPosition(270, 200);
            win.draw(tile);
        }*/

        if (sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 270 && event.mouseButton.x < 320 && event.mouseButton.y < 200 && event.mouseButton.x > 250)
            {
                tile.setFillColor(sf::Color::Red);
                tile.setPosition(270, 200);
                win.draw(tile);
            }
        }

        win.display();
    }
}
