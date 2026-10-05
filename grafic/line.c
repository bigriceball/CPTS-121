/*
p0 -------- p1
*/
#include "grafic.h"

void init(const char **appTitle_pp) //give a title to the window
{
    *appTitle_pp = "Line";
}

void redraw(void) //you need 2 points to draw a line
{
    double p0[2] = {-0.5, 0.0};
    double p1[2] = { 0.5, 0.0};

    color(0.0, 0.0, 0.0); //rgb values are between 0 and 1

    line(p0, p1);
}
