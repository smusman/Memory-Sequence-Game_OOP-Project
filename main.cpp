#include <windows.h>
#include <conio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include"HighScore.cpp"

using namespace std;
using namespace sf;
void mainmain();
void game();
void instructions();
string names_of_player[5]={"USMAN","AASHIR","OSAMA","HAMZA","Ali"};
class menu
{
private:
    int selecteditem;
    sf::Font font;
    sf::Text menuitem[4];

public:
    menu(float width, float height);
    ~menu();
    void draw(sf::RenderWindow &window);
    void moveup();
    void movedown();
    int presseditem()
    {
        return selecteditem;
    }

};

menu::menu(float width,float height)
{
    if(!font.loadFromFile("font.ttf"))
    {
        cout<<"Unable to load file"<<endl;
    }
    menuitem[0].setFont(font);
    menuitem[0].setColor(sf::Color(43, 79, 124));
    menuitem[0].setString("Start Game");
    menuitem[0].setPosition(sf::Vector2f(370,300));

    menuitem[1].setFont(font);
    menuitem[1].setColor(sf::Color(69,123,193));
    menuitem[1].setString("Instructions");
    menuitem[1].setPosition(sf::Vector2f(370,380));

    menuitem[2].setFont(font);
    menuitem[2].setColor(sf::Color(69,123,193));
    menuitem[2].setString("HighScore");
    menuitem[2].setPosition(sf::Vector2f(370,460));

    menuitem[3].setFont(font);
    menuitem[3].setColor(sf::Color(69,123,193));
    menuitem[3].setString("Quit");
    menuitem[3].setPosition(sf::Vector2f(370,540));

    selecteditem=0;
}

menu::~menu()
{

}
void menu::draw(sf::RenderWindow &window)
{
    for(int i=0; i < 4 ; i++)
    {
        window.draw(menuitem[i]);
    }
}

void menu::moveup()
{
    if(selecteditem-1>=0)
    {
        menuitem[selecteditem].setColor(sf::Color(69,123,193));
        selecteditem--;
        menuitem[selecteditem].setColor(sf::Color(43, 79, 124));
    }
}

void menu::movedown()
{
    if(selecteditem+1<4)
    {
        menuitem[selecteditem].setColor(sf::Color(69,123,193));
        selecteditem++;
        menuitem[selecteditem].setColor(sf::Color(43, 79, 124));
    }
}

//Instructions
void instructions()
{
    RenderWindow window(VideoMode(900, 900), "Number Sequence Game");

    sf::Texture texture;

    if(!texture.loadFromFile("background.jpg"))
    {
        cout<<"Error Loading background"<<endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        cout<<"Unable to load font"<<endl;
    }


    Text ins;
    ins.setFont(font);
    ins.setString("INSTRUCTIONS");
    ins.setCharacterSize(42);
    ins.setStyle(Text::Bold);
    ins.setStyle(Text::Underlined);
    ins.setPosition(Vector2f(350,150));
    ins.setFillColor(Color(69,123,193));

    Text ins1;
    ins1.setFont(font);
    ins1.setString("Repeat the given sequence of the number by");
    ins1.setCharacterSize(25);
    ins1.setPosition(Vector2f(250,250));
    ins1.setFillColor(Color(69,123,193));

    Text ins2;
    ins2.setFont(font);
    ins2.setString("enter the corresponding sequence in your");
    ins2.setCharacterSize(25);
    ins2.setPosition(Vector2f(250,290));
    ins2.setFillColor(Color(69,123,193));

    Text ins3;
    ins3.setFont(font);
    ins3.setString("keyboard");
    ins3.setCharacterSize(25);
    ins3.setPosition(Vector2f(250,330));
    ins3.setFillColor(Color(69,123,193));

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                window.close();
                break;
                /*case Event::KeyPressed:
                    switch(event.key.code)
                    {

                    }*/

            }
        }
        window.draw(sprite);
        window.draw(ins);
        window.draw(ins1);
        window.draw(ins2);
        window.draw(ins3);

        window.display();


}

}

int main()
{
    mainmain();
}
void mainmain()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Number Sequence Game");

    menu menu(window.getSize().x, window.getSize().y);

    sf::Texture texture;

    if(!texture.loadFromFile("background.jpg"))
    {
        cout<<"Error Loading background"<<endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        cout<<"Unable to load font"<<endl;
    }


    int width = window.getSize().x;

    int x=0;

    sf::Text text;
    text.setFont(font);
    text.setString("NUMBER SEQUENCE GAME");
    text.setCharacterSize(42);
    text.setPosition(sf::Vector2f(220,150));
    text.setStyle(sf::Text::Bold);
    text.setStyle(sf::Text::Underlined);



    text.setFillColor(sf::Color(69,123,193));

    text.setFillColor(sf::Color(69,123,193));



    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.moveup();
                    break;
                case sf::Keyboard::Down:
                    menu.movedown();
                    break;
                case sf::Keyboard::Return:
                    switch(menu.presseditem())
                    {
                    case 0:
                        {

                        cout<<"Start game pressed"<<endl;
                        Sleep(2000);
                        game();




                            break;
                        }


                    case 1:
                        {

                        cout<<"instructions pressed"<<endl;
                        instructions();
                        break;

                        }

                    case 2:
                        {

                        cout<<"Highscore"<<endl;
                        High_score();
                        break;

                        }


                    case 3:
                        {

                        cout<<"Quit"<<endl;
                        window.close();
                        break;

                        }
                    }

                }

                break;
            case sf::Event::Closed:
                window.close();
                break;

            }
        }

        window.clear();

        window.draw(sprite);
        menu.draw(window);
        window.draw(text);
        window.display();

    }

}

static int score=0;
static int level=3;
void game()
{


    right_loop:
    int aashir=0;
    bool enter_digits[20]; char number_checker[20];int number_checker_int[20];
    for(int klo=0;klo<20;klo++)
    {
        number_checker[klo]='\0';
    }
    bool sequence_is_right=false;
    RenderWindow window(VideoMode(900, 900), "Number Sequence Game");

    Texture texture;

    if(!texture.loadFromFile("background.jpg"))
    {
        cout<<"Error Loading background"<<endl;
    }

    Sprite sprite;
    sprite.setTexture(texture);

    Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        cout<<"Unable to load font"<<endl;
    }


    Text s;
    s.setFont(font);
    s.setString("Displaying Sequence ");
    s.setCharacterSize(42);
    s.setPosition(Vector2f(220,150));
    s.setStyle(Text::Bold);
    s.setFillColor(Color(69,123,193));

    Text q;
    q.setFont(font);
    q.setString("Enter Sequence: ");
    q.setCharacterSize(42);
    q.setPosition(Vector2f(220,150));
    q.setStyle(Text::Bold);
    q.setFillColor(Color(69,123,193));

    Text e;
    e.setFont(font);
    e.setString("Your Score: ");
    e.setCharacterSize(42);
    e.setPosition(Vector2f(220,450));
    e.setStyle(Text::Bold);
    e.setFillColor(Color(69,123,193));

    Text u;
    u.setFont(font);
    u.setString("0");
    u.setCharacterSize(42);
    u.setPosition(Vector2f(450,350));
    u.setStyle(Text::Bold);
    u.setFillColor(Color(69,123,193));


    Text h;
    h.setFont(font);
    h.setString("Game Over!");
    h.setCharacterSize(80);
    h.setPosition(Vector2f(250,150));
    h.setStyle(Text::Bold);
    h.setFillColor(Color(69,123,193));

    Text arr1[11];
    for(int k=0; k<11; k++)
    {
        arr1[k].setFont(font);
        arr1[k].setString("Press Num keys");
        arr1[k].setCharacterSize(42);
        arr1[k].setPosition(Vector2f(320,250));
        arr1[k].setStyle(Text::Bold);
        arr1[k].setFillColor(Color(69,123,193));
    }
    Text score1[11];
    for(int k=0; k<11; k++)
    {
        score1[k].setFont(font);
        score1[k].setString("Press Num keys");
        score1[k].setCharacterSize(42);
        score1[k].setPosition(Vector2f(250,550));
        score1[k].setStyle(Text::Bold);
        score1[k].setFillColor(Color(69,123,193));
    }
    Text score2[11];
    for(int k=0; k<11; k++)
    {
        score2[k].setFont(font);
        score2[k].setString("Press Num keys");
        score2[k].setCharacterSize(42);
        score2[k].setPosition(Vector2f(450,550));
        score2[k].setStyle(Text::Bold);
        score2[k].setFillColor(Color(69,123,193));
    }

    {

    int arr[level];

    srand(time(0));

    for(int i=0; i<level; i++)  //Random number array generator
    {
        arr[i]=rand()%10;
    }


    char x[level];
    char score_char;
    Text a[level],show;

    for(int i=0 ; i<level; i++) //Sequence storing int to char
    {
        //x[i]=arr[i];
        sprintf(&x[i],"%d",arr[i]);
        cout<<&x[i];
    }

    for(int i=0; i<level; i++) //string Displayer
    {
        a[i].setFont(font);
        a[i].setCharacterSize(35);
        a[i].setColor(Color(69,123,193));
        a[i].setString(&x[i]);
        a[i].setPosition(Vector2f(450+(i*50),250));

    }

    while (window.isOpen())
    {
        Event event;
        while( window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(s);
        window.display();

        Sleep(1000);


        window.draw(sprite);
        window.draw(s);
        window.draw(a[0]);
        window.display();


        Sleep(3000);


        window.clear();
        window.draw(sprite);
        window.draw(q);
        window.display();


        break;
    }

    while (window.isOpen())
    {

    window.draw(sprite);
    window.draw(q);
    window.display();

    break;

    }

    while(window.isOpen())
    {
        Event event;

        while( window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                switch(event.key.code)
                {
                case Keyboard::Numpad0:
                    number_checker_int[aashir]=0;
                    number_checker[aashir]='0';
                    window.draw(sprite);
                    window.draw(q);
                    arr1[0].setString(number_checker);
                    window.draw(arr1[0]);

                    aashir++;
                    window.display();
                    cout<<0;
                    break;

                case Keyboard::Numpad1:
                    number_checker_int[aashir]=1;
                    number_checker[aashir]='1';
                    window.draw(sprite);
                    window.draw(q);
                    arr1[1].setString(number_checker);
                    window.draw(arr1[1]);

                    aashir++;
                    window.display();
                    cout<<1;
                    break;

                case Keyboard::Numpad2:
                    number_checker[aashir]='2';
                    number_checker_int[aashir]=2;
                    window.draw(sprite);
                    window.draw(q);
                    arr1[2].setString(number_checker);
                    window.draw(arr1[2]);
                    aashir++;
                    window.display();
                    cout<<2;
                    break;

                case Keyboard::Numpad3:
                    number_checker_int[aashir]=3;
                    number_checker[aashir]='3';
                    window.draw(sprite);
                    window.draw(q);
                    arr1[3].setString(number_checker);
                    window.draw(arr1[3]);

                    aashir++;
                    window.display();
                    cout<<3;
                    break;

                case Keyboard::Numpad4:
                    window.draw(sprite);
                    number_checker_int[aashir]=4;
                    number_checker[aashir]='4';
                    window.draw(q);
                    arr1[4].setString(number_checker);
                    window.draw(arr1[4]);

                    aashir++;
                    window.display();
                    cout<<4;
                    break;

                case Keyboard::Numpad5:
                    window.draw(sprite);
                    number_checker_int[aashir]=5;
                    number_checker[aashir]='5';
                    window.draw(q);
                    arr1[5].setString(number_checker);
                    window.draw(arr1[5]);

                    aashir++;
                    window.display();
                    cout<<5;
                    break;

                case Keyboard::Numpad6:
                    window.draw(sprite);
                    number_checker[aashir]='6';
                    number_checker_int[aashir]=6;
                    window.draw(q);
                    arr1[6].setString(number_checker);
                    window.draw(arr1[6]);

                    aashir++;
                    window.display();
                    cout<<6;
                    break;

                case Keyboard::Numpad7:

                    number_checker[aashir]='7';
                    number_checker_int[aashir]=7;
                    window.draw(sprite);
                    window.draw(q);
                    arr1[7].setString(number_checker);
                    window.draw(arr1[7]);
                    aashir++;
                    window.display();
                    cout<<7;
                    break;

                case Keyboard::Numpad8:
                    window.draw(sprite);
                    number_checker[aashir]='8';
                    number_checker_int[aashir]=8;
                    window.draw(q);
                    arr1[8].setString(number_checker);
                    window.draw(arr1[8]);

                    aashir++;
                    window.display();
                    cout<<8;
                    break;

                case Keyboard::Numpad9:
                    window.draw(sprite);
                    number_checker[aashir]='9';
                    number_checker_int[aashir]=9;
                    window.draw(q);
                    arr1[9].setString(number_checker);
                    window.draw(arr1[9]);
                    window.display();

                    aashir++;
                    cout<<9;
                    break;

                case Keyboard::Escape:
                    window.close();
                    break;

                case Keyboard::Return:
                    window.draw(sprite);
                    window.draw(q);
                    arr1[10].setString(number_checker);
                    window.draw(arr1[10]);
                    window.display();
                    if(aashir>level)
                    {
                    window.draw(sprite);
                    window.draw(s);
                    arr1[10].setString("GAME OVER ");
                    window.draw(arr1[10]);
                    window.draw(sprite);
                     window.draw(q);
                     window.display();
                    score1[10].setString("YOUR SCORE : ");
                     window.draw(score1[10]);
                      window.draw(sprite);
                      window.draw(q);
                    sprintf(&score_char,"%d",score);
                    score2[10].setString(score_char);
                    window.draw(score2[10]);
                    window.display();
                    Sleep(1000);

                    if(level<7)
                    {
                    add_highscore(names_of_player[rand()%3],score);
                    get_highscore();
                    }
                    goto m;





                    }
                    if(aashir==level)
                    {
                        for(int ko=0;ko<level;ko++)
                        {
                            if(x[ko]!=number_checker[ko])
                                {
                                    if(ko==(level-1))
                                    {
                                    window.draw(sprite);
                                    window.draw(e);
                                    //score1[10].setString("YOUR SCORE : ");
                                    //window.draw(score1[10]);
                                    window.display();
                                    window.draw(sprite);
                                    window.draw(e);
                                    sprintf(&score_char,"%d",score);
                                    score2[10].setString(score_char);
                                    window.draw(score2[10]);
                                    window.draw(h);
                                    window.display();

                                    Sleep(3000);



                                    if(level<7)
                                    {
                                        cout<<"Here";
                                    add_highscore(names_of_player[rand()%3],score);
                                    get_highscore();
                                        }

                                    goto m;




                                    }
                                }
                            if(x[ko]==number_checker[ko])
                                {
                                    if(ko==(level-1))
                                    {
                                    score++;
                                    window.draw(e);
                                    sprintf(&score_char,"%d",score);
                                    score2[10].setString(score_char);
                                    window.draw(score2[10]);
                                    window.display();
                                    Sleep(3000);
                                    level++;

                                    goto right_loop;
                                    }

                                }
                        }

                    }

                }
            }
        }


    }
    }
    m:
        return;

}



