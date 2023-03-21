#include <iostream>
#include "class.h"

int main()
{
    Object order;

    order.configuration();
    for (int i = 0; i < order.loop_count(); i++)
    {
        order.input();
        //order.solve_bouble();
        //order.solve_quick();
        order.solve_insanity();
        order.save();
    }
    order.save_time();
}