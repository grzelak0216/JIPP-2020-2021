#include "funk.h"

namespace SNAKE
{
    int GAME_OVER = -2;
    int SCORE = 0;

    int foodx, foody;
    int food = 1;

    int length = 5;

    int posSnake[300][2] = {{11, 14}, {11, 13}, {11, 12}, {11, 11}, {11, 10}, {11, 9}};
    int xr = 0, yr = 1;

    int startPosSnake[6][2] = {{11, 14}, {11, 13}, {11, 12}, {11, 11}, {11, 10}, {11, 9}};

    void specialkey(int key, int x, int y)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
        {
            cout << "\n up: " << GAME_OVER;
            if (GAME_OVER == 0 || GAME_OVER == -1)
            {
                cout << "\n   up1 ";
                if (yr != -1)
                {
                    yr = 1;
                    xr = 0;
                }
            }
            else
            {
                cout << "\n   up2 ";
                if (GAME_OVER == 1)
                {
                    if (yr + 1 != 2)
                    {
                        yr++;
                    }
                }
                else
                {
                    yr = 1;
                }
            }

            glutPostRedisplay();
            break;
        }
        case GLUT_KEY_DOWN:
        {
            cout << "\n down: " << GAME_OVER;
            if (GAME_OVER == 0 || GAME_OVER == -1)
            {
                cout << "\n   down1 ";
                if (yr != 1)
                {
                    yr = -1;
                    xr = 0;
                }
            }
            else
            {
                cout << "\n   down2 ";
                if (GAME_OVER == 1)
                {
                    if (yr - 1 != -2)
                    {
                        yr--;
                    }
                }
                else
                {
                    yr = 0;
                }
            }
            glutPostRedisplay();
            break;
        }
        case GLUT_KEY_LEFT:
        {
            cout << "\n left: " << GAME_OVER;
            if (GAME_OVER == 0 || GAME_OVER == -1)
            {
                cout << "\n   left1 ";
                if (xr != 2)
                {
                    xr = -2;
                    yr = 0;
                }
            }

            glutPostRedisplay();
            break;
        }
        case GLUT_KEY_RIGHT:
        {
            cout << "\n right: " << GAME_OVER;
            if (GAME_OVER == 0 || GAME_OVER == -1)
            {
                cout << "\n   right1 ";
                if (xr != -2)
                {
                    xr = 2;
                    yr = 0;
                }
            }
            else
            {
                if (GAME_OVER != 2)
                {
                    cout << "\n   right2 ";
                    if (yr == 1)
                    {
                        if (GAME_OVER == 1)
                        {
                            for (int i = 0; i < length; i++)
                            {
                                if (i < 5)
                                {
                                    posSnake[i][0] = startPosSnake[i][0];
                                    posSnake[i][1] = startPosSnake[i][1];
                                }
                                else
                                {
                                    posSnake[i][0] = 0;
                                    posSnake[i][1] = 0;
                                }
                                length = 5;
                            }
                        }
                        xr = 0;
                        yr = 0;
                        GAME_OVER = -1;
                    }
                    else
                    {
                        if (yr == -1)
                        {
                            exit(0);
                            cout << "\n player exit";
                        }
                        else
                        {
                            if (GAME_OVER == -2)
                            {
                                exit(0);
                                cout << "\n player exit";
                            }
                            else
                            {
                                GAME_OVER = 2;
                            }
                        }
                    }
                }
                else
                {
                    GAME_OVER = 1;
                }
            }

            glutPostRedisplay();
            break;
        }
        defoult:
            break;
        }
    }

    void moveSnake()
    {

        for (int i = length - 1; i > 0; i--)
        {
            posSnake[i][0] = posSnake[i - 1][0];
            posSnake[i][1] = posSnake[i - 1][1];
        }

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
            {
                if (yr != 0)
                {
                    if (yr > 0)
                    {
                        posSnake[0][1]++;
                    }
                    else
                    {
                        posSnake[0][1]--;
                    }
                }
                else
                {
                    if (xr > 0)
                    {
                        posSnake[0][0]++;
                    }
                    else
                    {
                        posSnake[0][0]--;
                    }
                }
                if (posSnake[0][0] < 1 || posSnake[0][0] > 22 || posSnake[0][1] < 1 || posSnake[0][1] > 22)
                {
                    GAME_OVER = 1;
                    number++;
                    cout << "\n edge";
                    //exit(0);
                }
                else
                {
                    if (posSnake[0][0] == foodx && posSnake[0][1] == foody)
                    {
                        SCORE++;
                        food = 1;
                        //					posSnake[length+1][0] = posSnake[length][0];
                        //        			posSnake[length+1][1] = posSnake[length][1];

                        length++;
                    }
                }
                for (int j = 1; j < length; j++)
                {
                    if (posSnake[0][0] == posSnake[j][0] && posSnake[0][1] == posSnake[j][1])
                    {
                        number++;
                        GAME_OVER = 1;
                        cout << "\n body";
                        //exit(0);
                    }
                }
            }
        }
    }
} // namespace SNAKE