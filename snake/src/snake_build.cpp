#include "funk.h"

namespace SNAKE
{
    Draw draw;
    Score S;
    struct text
    {
        string txt1 = "Snake Game";
        string opt1 = "PLAY";
        string opt2 = "EXIT";
        string opt3 = "RETRY";
        string opt4 = "SCORE";
        string optcon = "Press right dart to confirm";
        string txt2 = "Press any dart button";
        string txt3 = "Your score: ";
        string txt4 = "GAME OVER";
        string txt5 = "Thank You for game";
        string txt6 = "Your last score: ";
        string txt7 = "Press right dart to back to menu ";
        int i = 0;
    } str;

    void Build::gameSnake()
    {
        draw.board();
        draw.drawFood();

        moveSnake();
        draw.drawSnake();

        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(25, 5, str.txt3);
        drawString24(150, 5, intToStr(SCORE));
        glFlush();
        //cout<<2;
    }

    void Build::beginSnake0()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(225, 400, str.txt1);
        drawString10(232, 390, str.optcon);

        if (yr == 1)
        {
            glColor3f(1.0f, 1.0f, 1.0f);
            drawString24(257, 310, str.opt1);
            glColor3f(0.4f, 0.4f, 0.4f);
            drawString24(257, 280, str.opt2);
        }
        else
        {
            glColor3f(0.4f, 0.4f, 0.4f);
            drawString24(257, 310, str.opt1);
            glColor3f(1.0f, 1.0f, 1.0f);
            drawString24(257, 280, str.opt2);
        }

        glFlush();

        Sleep(1);
    }

    void Build::beginSnake1()
    {
        draw.board();
        draw.drawSnake();
        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(225, 400, str.txt1);
        drawString10(250, 390, str.txt2);
        glFlush();

        cout << "\n " << yr << " " << xr;

        SCORE = 0;

        if (yr > 0 || xr != 0)
        {
            GAME_OVER = 0;
        }
        Sleep(1);
    }

    void Build::endSnake()
    {
        draw.board();

        draw.drawSnake();

        S.make_list();

        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(225, 400, str.txt4);
        drawString24(200, 370, str.txt5);
        drawString24(225, 340, str.txt3);
        drawString24(350, 340, intToStr(SCORE));

        if (yr == 1)
        {
            glColor3f(1.0f, 1.0f, 1.0f);
            drawString24(257, 310, str.opt3);
            glColor3f(0.4f, 0.4f, 0.4f);
            drawString24(250, 280, str.opt4);
            glColor3f(0.4f, 0.4f, 0.4f);
            drawString24(257, 250, str.opt2);
        }
        else
        {
            if (yr == 0)
            {
                glColor3f(0.4f, 0.4f, 0.4f);
                drawString24(257, 310, str.opt3);
                glColor3f(1.0f, 1.0f, 1.0f);
                drawString24(250, 280, str.opt4);
                glColor3f(0.4f, 0.4f, 0.4f);
                drawString24(257, 250, str.opt2);
            }
            else
            {
                glColor3f(0.4f, 0.4f, 0.4f);
                drawString24(257, 310, str.opt3);
                glColor3f(0.4f, 0.4f, 0.4f);
                drawString24(250, 280, str.opt4);
                glColor3f(1.0f, 1.0f, 1.0f);
                drawString24(257, 250, str.opt2);
            }
        }

        glFlush();

        //cout<<3;
    }

    void Build::scoreSnake()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawString24(225, 500, str.txt6);
        drawString10(232, 490, str.txt7);

        S.print_list();

        drawString24(265, 120, str.opt2);

        glFlush();
    }

} // namespace SNAKE