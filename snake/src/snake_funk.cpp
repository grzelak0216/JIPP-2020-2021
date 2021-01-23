#include "funk.h"

namespace SNAKE
{
    Build build;
    void buildSnake()
    {

        if (GAME_OVER < 0)
        {
            if (GAME_OVER == -2)
            {
                build.beginSnake0();
            }
            else
            {
                build.beginSnake1();
            }
        }
        else
        {
            if (GAME_OVER == 0)
            {
                build.gameSnake();
            }
            else
            {
                if (GAME_OVER == 1)
                {
                    build.endSnake();
                }
                else
                {
                    build.scoreSnake();
                }
            }
        }
    }

    void drawString24(int x, int y, string str)
    {
        glRasterPos2d(x, y);

        int len = str.length();
        for (int i = 0; i < len; i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }

    void drawString10(int x, int y, string str)
    {
        glRasterPos2d(x, y);

        int len = str.length();
        for (int i = 0; i < len; i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, str[i]);
    }

    string intToStr(int n)
    {
        std::string ret, tmp;

        if (n < 0)
        {
            ret = "-";
            n = -n;
        }

        do
        {
            tmp += (char)(n % 10 + '0');
            n -= n % 10;
        } while (n /= 10);

        for (int i = tmp.size() - 1; i >= 0; i--)
            ret += tmp[i];

        return ret;
    }

} // namespace SNAKE
