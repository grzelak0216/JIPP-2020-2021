#include "funk.h"

char pass;

string txt1 = "Snake Game";
string opt1 = "PLAY";
string opt2 = "EXIT";
string opt3 = "RETRY";
string optcon = "Press right dart to confirm";
string txt2 = "Press any dart button";
string txt3 = "Your score: ";
string txt4 = "GAME OVER";
string txt5 = "Thank You for game";

void gameSnake()
{
    board();
    drawFood();

    moveSnake();
    drawSnake();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawString24(25, 5, txt3);
    drawString24(150, 5, intToStr(SCORE));
    glFlush();
    //cout<<2;
}

void beginSnake0()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawString24(225, 400, txt1);
    drawString10(232, 390, optcon);

    if (yr == 1)
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(257, 310, opt1);
        glColor3f(0.4f, 0.4f, 0.4f);
        drawString24(257, 280, opt2);
    }
    else
    {
        glColor3f(0.4f, 0.4f, 0.4f);
        drawString24(257, 310, opt1);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(257, 280, opt2);
    }

    glFlush();

    Sleep(1);
}

void beginSnake1()
{
    board();
    drawSnake();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawString24(225, 400, txt1);
    drawString10(250, 390, txt2);
    glFlush();

    cout << "\n " << yr << " " << xr;

    if (yr > 0 || xr != 0)
    {
        GAME_OVER = 0;
    }
    Sleep(1);
}

void endSnake()
{
    board();

    drawSnake();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawString24(225, 400, txt4);
    drawString24(200, 370, txt5);
    drawString24(225, 340, txt3);
    drawString24(350, 340, intToStr(SCORE));

    if (yr == 1)
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(257, 310, opt3);
        glColor3f(0.0f, 0.0f, 0.0f);
        drawString24(265, 280, opt2);
    }
    else
    {
        glColor3f(0.0f, 0.0f, 0.0f);
        drawString24(257, 310, opt3);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(265, 280, opt2);
    }

    glFlush();

    //cout<<3;
}

void bildSnake()
{
    if (GAME_OVER < 0)
    {
        if (GAME_OVER == -2)
        {
            beginSnake0();
        }
        else
        {
            beginSnake1();
        }
    }
    else
    {
        if (GAME_OVER == 0)
        {
            gameSnake();
        }
        else
        {
            endSnake();
        }
    }
}