#include <SFML/Graphics.hpp>
#include <windows.h>
#include "board.h"
using namespace std;
int main()
{
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
    //1200 * 725
    sf::RenderWindow window(sf::VideoMode(2400 / 2, 1450 / 2), "circuit teaching demo");
    sf::Style::None;

    board win;
    win.setMain();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i position_i = sf::Mouse::getPosition(window);
                    sf::Vector2f position_f = window.mapPixelToCoords(position_i);
                    string sName= win.clickOnSwitch(position_f.x, position_f.y);
                    if (sName == "button") {
                        win.setBoard();
                    }
                    else if (sName == "return") {
                        win.setMain();
                    }
                    if ( sName!= "false") {
                        if (sName == "s1") {
                            win.setS1();
                        }
                        else if (sName == "s13") {
                            win.setS13("none");
                        }
                        else {
                            win.setGeneral(sName,"none");
                        }
                    }
                }
            }
        }

        window.clear();
        for (auto it : win.getMap()) {
            window.draw(it.second);
        }
        window.display();
    }

    FreeConsole();
    return 0;
}