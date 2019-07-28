#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{

    f::RenderWindow window(sf::VideoMode(900, 900), "Number Sequence Game");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
                case sf::Event::Closed:
                window.close();
                break;
        }
    }

        window.clear();

        window.display();
    }

    return 0;
}
