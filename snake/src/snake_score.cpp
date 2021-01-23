#include "funk.h"
namespace SNAKE
{
    int number = 0;
    void Score::make_list()
    {
        score_list[number] = SCORE;
        cout << number << "<-ilosc wynikow\n";
    }

    void Score::print_list()
    {
        cout << number << "<-ilosc wynikow\n";
        double y = 450;
        int j = 0;
        if (number > 10)
        {
            j = number - 10;
        }

        while (j < 10 && j <= number)
        {
            drawString24(290, y, intToStr(score_list[j]));
            y -= 25;
            j++;
        }
    }

} // namespace SNAKE
