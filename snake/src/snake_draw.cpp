#include "funk.h"

namespace SNAKE
{
    int c = 0;
    int b = 0;

    int pom = 25;

    void Draw::partSnake(int x, int y)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(x + pom, y + pom);
        glColor3f(0.5f, 0.5f, 0.0f);
        glVertex2i(x + pom, y);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(x, y);
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex2i(x, y + pom);

        glEnd();
    }

    void Draw::drawSnake()
    {
        for (int i = 0; i < length; i++)
        {
            partSnake(posSnake[i][0] * 25, posSnake[i][1] * 25);
        }
    }

    void Draw::drawFood()
    {
        if (food)
        {
            foodx = 1 + rand() % 22;
            foody = 1 + rand() % 22;

            for (int j = 1; j < length; j++)
            {
                if (posSnake[j][0] == foodx && posSnake[j][1] == foody)
                {
                    food = 1;
                    break;
                }
                else
                {
                    food = 0;
                }
            }
        }

        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(25 * foodx + pom, 25 * foody + pom);
        glColor3f(1.0f, 0.2f, 0.2f);
        glVertex2i(25 * foodx + pom, 25 * foody);
        glColor3f(1.0f, 0.1f, 0.1f);
        glVertex2i(25 * foodx, 25 * foody);
        glColor3f(1.0f, 0.3f, 0.3f);
        glVertex2i(25 * foodx, 25 * foody + pom);

        glEnd();
    }

    void Draw::drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
    {
        // if color is 0 then draw white box and change value of color = 1
        if (c == 0)
        {
            glColor3f(0.0f, 0.4f, 0.0f); // green color value
            c = 1;
        }
        else
        {
            glColor3f(0.6f, 0.6f, 0.0f); // yellow color value
            c = 0;
        }

        if (b == 1)
        {
            glColor3f(0.1f, 0.1f, 0.1f);
            b = 0;
        }

        // Draw Square
        glBegin(GL_POLYGON);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);
        glVertex2i(x4, y4);
        glEnd();
    }

    void Draw::board()
    {
        glClear(GL_COLOR_BUFFER_BIT); // Clear display window

        for (GLint x = 0; x <= 625; x += 25)
        {
            for (GLint y = 0; y <= 600; y += 25)
            {
                if (x == 0 || y == 0 || x == 575 || y == 575)
                {
                    b = 1;
                }
                drawSquare(x, y + 25, x + 25, y + 25, x + 25, y, x, y);
            }
        }
    }
} // namespace SNAKE
