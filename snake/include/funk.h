#include "header.h"

extern int GAME_OVER;
extern int SCORE;

extern int foodx, foody;
extern int food;

extern int length;

extern int posSnake[300][2];
extern int xr, yr;

void partSnake(int x, int y);

void specialkey(int key, int x, int y);

void drawSnake();

void moveSnake();

void drawFood();

void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4);

void board();

void drawString24(int x, int y, string str);

void drawString10(int x, int y, string str);

string intToStr(int n);

void gameSnake();

void beginSnake0();

void beginSnake1();

void endSnake();

void bildSnake();
