#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace sf;
using namespace std;
static int aashir=0;
static int score=0;

void game()
{
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
    e.setPosition(Vector2f(220,350));
    e.setStyle(Text::Bold);
    e.setFillColor(Color(69,123,193));

    Text u;
    u.setFont(font);
    u.setString("0");
    u.setCharacterSize(42);
    u.setPosition(Vector2f(450,250));
    u.setStyle(Text::Bold);
    u.setFillColor(Color(69,123,193));


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

    for(int level=3;level<50;level++)
    {
    right_loop:
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
                    window.draw(sprite);
                    window.draw(q);
                    arr1[0].setString("0");
                    window.draw(arr1[0]);
                    number_checker_int[aashir]=0;
                    number_checker[aashir]='0';
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


                case Keyboard::Return:
                    window.draw(sprite);
                    window.draw(q);
                    arr1[10].setString(number_checker);
                    window.draw(arr1[10]);
                    window.display();
                    if(aashir>level)
                    {
                    window.draw(sprite);
                    window.draw(q);
                    arr1[10].setString("Your Sequence is wrong ");
                    window.draw(arr1[10]);
                    window.display();
                    window.draw(sprite);
                     window.draw(q);
                    score1[10].setString("YOUR SCORE : ");
                     window.draw(score1[10]);
                      window.display();
                      window.draw(sprite);
                      window.draw(q);
                      sprintf(&score_char,"%d",score);
                    score2[10].setString(score_char);
                    window.draw(score2[10]);
                    window.display();
                    Sleep(1000);
                    add_highscore(names_of_player[rand()%5],score);
                    window.close();
                    main();

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
                                    window.draw(q);
                                    arr1[10].setString("Your Sequence is wrong ");
                                    window.draw(arr1[10]);
                                    window.display();
                                    window.draw(sprite);
                                    window.draw(q);
                                    score1[10].setString("YOUR SCORE : ");
                                    window.draw(score1[10]);
                                    window.display();
                                    window.draw(sprite);
                                    window.draw(q);
                                    sprintf(&score_char,"%d",score);
                                    score2[10].setString(score_char);
                                    window.draw(score2[10]);
                                    add_highscore(names_of_player[rand()%5],score);
                                    window.display();
                                    sleep(1000);
                                    window.close();
                                    main();



                                    }
                                }
                            if(x[ko]==number_checker[ko])
                                {
                                    if(ko==(level-1))
                                    {
                                    window.draw(sprite);
                                    window.draw(q);
                                    arr1[10].setString("Your Sequence is RIGHT : " );
                                    score++;
                                    window.draw(arr1[10]);
                                    window.display();
                                    score1[10].setString("YOUR SCORE : ");
                                    window.draw(score1[10]);
                                    window.display();
                                    window.draw(sprite);
                                    window.draw(q);
                                    sprintf(&score_char,"%d",score);
                                    score2[10].setString(score_char);
                                    window.draw(score2[10]);
                                    window.display();
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

}

