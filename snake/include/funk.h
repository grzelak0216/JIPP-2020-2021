#include "header.h"

namespace SNAKE
{

    extern int GAME_OVER;
    extern int SCORE;

    extern int foodx, foody;
    extern int food;

    extern int length;

    extern int posSnake[300][2];
    extern int xr, yr;

    extern int number;

    class Build
    {
    protected:
    private:
        struct text;

    public:
        void gameSnake();

        void beginSnake0();

        void beginSnake1();

        void endSnake();

        void scoreSnake();
    };

    class Draw
    {
    private:
        int c = 0;
        int b = 0;

        int pom = 25;

    public:
        void partSnake(int x, int y);

        void drawSnake();

        void drawFood();

        void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4);

        void board();
    };

    class Score
    {
    private:
        std::map<int, int> score_list;

    public:
        void make_list();

        void print_list();
    };

    void specialkey(int key, int x, int y);

    void moveSnake();

    void drawString24(int x, int y, string str);

    void drawString10(int x, int y, string str);

    string intToStr(int n);

    void buildSnake();

} // namespace SNAKE