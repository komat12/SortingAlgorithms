#include <iostream>
#include "class.h"

int main()
{
    Object order;

    order.configuration();
    order.input();
    //order.solve_bouble();
    order.solve_quick();
    order.save();
}