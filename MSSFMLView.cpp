#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

class Board
{

    unsigned int boardHeight = 600;
    unsigned int boardWidth = 800;

public:
    sf::RenderWindow win(sf::VideoMode(boardWidth, boardHeight), "Saper");

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event)) //tutaj zdarzenia
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
            //win.clear();
            //view.draw(win);
            win.display();
        }
    }
};