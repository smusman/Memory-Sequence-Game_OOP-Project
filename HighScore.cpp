#include <iostream>
#include<windows.h>
#include<fstream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void get_highscore();
void add_highscore(string name,int a);
void High_score()
{
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



    Text hs, n1, n2, n3, n4, n5, n;
    Text s1, s2, s3, s4, s5 ,s;

    hs.setFont(font);
    hs.setString("HIGHSCORE");
    hs.setCharacterSize(50);
    hs.setPosition(Vector2f(350,80));
    hs.setStyle(Text::Bold);
    hs.setStyle(Text::Underlined);
    hs.setFillColor(Color(69,123,193));

    n.setFont(font);
    n.setString("NAME");
    n.setCharacterSize(30);
    n.setPosition(Vector2f(250,180));
    n.setStyle(Text::Bold);
    n.setStyle(Text::Underlined);
    n.setFillColor(Color(69,123,193));

    s.setFont(font);
    s.setString("SCORE");
    s.setCharacterSize(30);
    s.setPosition(Vector2f(540,180));
    s.setStyle(Text::Bold);
    s.setStyle(Text::Underlined);
    s.setFillColor(Color(69,123,193));


    n1.setFont(font);
    n1.setString("Name1 ");
    n1.setCharacterSize(30);
    n1.setPosition(Vector2f(250,250));
    n1.setFillColor(Color(69,123,193));


    n2.setFont(font);
    n2.setString("Name2 ");
    n2.setCharacterSize(30);
    n2.setPosition(Vector2f(250,310));
    n2.setFillColor(Color(69,123,193));


    n3.setFont(font);
    n3.setString("Name3 ");
    n3.setCharacterSize(30);
    n3.setPosition(Vector2f(250,370));
    n3.setFillColor(Color(69,123,193));


    n4.setFont(font);
    n4.setString("Name4 ");
    n4.setCharacterSize(30);
    n4.setPosition(Vector2f(250,430));
    n4.setFillColor(Color(69,123,193));


    n5.setFont(font);
    n5.setString("Name5 ");
    n5.setCharacterSize(30);
    n5.setPosition(Vector2f(250,490));
    n5.setFillColor(Color(69,123,193));


    s1.setFont(font);
    s1.setString("Score1 ");
    s1.setCharacterSize(30);
    s1.setPosition(Vector2f(580,250));
    s1.setStyle(Text::Bold);
    s1.setFillColor(Color(69,123,193));


    s2.setFont(font);
    s2.setString("Score2 ");
    s2.setCharacterSize(30);
    s2.setPosition(Vector2f(580,310));
    s2.setFillColor(Color(69,123,193));


    s3.setFont(font);
    s3.setString("Score3 ");
    s3.setCharacterSize(30);
    s3.setPosition(Vector2f(580,370));
    s3.setFillColor(Color(69,123,193));


    s4.setFont(font);
    s4.setString("Score4 ");
    s4.setCharacterSize(30);
    s4.setPosition(Vector2f(580,430));
    s4.setFillColor(Color(69,123,193));


    s5.setFont(font);
    s5.setString("Score5 ");
    s5.setCharacterSize(30);
    s5.setPosition(Vector2f(580,490));
    s5.setFillColor(Color(69,123,193));

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

        ifstream file_name,file_score;
        string name1[50];
        int score1[50];
        char scorechanger[10];
        file_name.open("Name.txt");
        file_score.open("score.txt");
        int tk=0;
        while(getline(file_name,name1[tk])){
        file_score>>score1[tk];
        tk++;
            }
        window.draw(sprite);
        window.draw(hs);
        n1.setString(name1[0]);
        window.draw(n1);
        n2.setString(name1[1]);
        window.draw(n2);
        n3.setString(name1[2]);
        window.draw(n3);
        n4.setString(name1[3]);
        window.draw(n4);
        n5.setString(name1[4]);
        window.draw(n5);
        sprintf(scorechanger,"%d",score1[0]);
        s1.setString(scorechanger);
        window.draw(s1);
        sprintf(scorechanger,"%d",score1[1]);
        s2.setString(scorechanger);
        window.draw(s2);
        sprintf(scorechanger,"%d",score1[2]);
        s3.setString(scorechanger);
        window.draw(s3);
        sprintf(scorechanger,"%d",score1[3]);
        s4.setString(scorechanger);
        window.draw(s4);
        sprintf(scorechanger,"%d",score1[4]);
        s5.setString(scorechanger);
        window.draw(s5);
        window.draw(s);
        window.draw(n);
        window.display();


    }

}
void add_highscore(string name,int a)
{
    ofstream file_name,file_score;
    file_name.open("Name.txt",ios::app);
    file_name<<name<<endl;
    file_name.close();
    file_score.open("score.txt",ios::app);
    file_score<<a<<endl;
    file_score.close();

}

void get_highscore()
{
    ifstream file_name,file_score;
    string name1[50];
    int score1[50];
    file_name.open("Name.txt");
    file_score.open("score.txt");
    int tk=0;
    while(getline(file_name,name1[tk])){
        file_score>>score1[tk];
        tk++;
    }
    for(int l=0;l<(tk-1);l++){
    for(int o=0;o<(tk-1);o<tk,o++)
    {
        if(score1[o+1]>score1[o])
        {
            swap(score1[o],score1[o+1]);
            swap(name1[o],name1[o+1]);
        }
    }
    }
    file_name.close();
    file_name.close();
     ofstream file_name1,file_score1;
     file_score1.open("score.txt");
     file_name1.open("Name.txt");
    for(int p=0;p<(tk);p++)
    {
        file_name1<<name1[p]<<endl;
        file_score1<<score1[p]<<endl;
    }

}
void get_view_highscore()
{
    ifstream file_name,file_score;
    string name1[50];
    int score1[50];
    file_name.open("Name.txt");
    file_score.open("score.txt");
    int tk=0;
    while(getline(file_name,name1[tk])){
        file_score>>score1[tk];
        tk++;
    }
}
