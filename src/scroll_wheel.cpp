#include "scroll_wheel.h"
#include <iostream>

void scrollWheel(int* val, int mode)
{
    static int scroll = 0;
    if (mode == 0) // set
    {
        scroll = *val;
    }
    else // get
    {
        *val = scroll;
    }
}

int getScroll()
{
    int val;
    scrollWheel(&val, 1);
    return val;
}

void setScroll(int scroll)
{
    scrollWheel(&scroll, 0);
}