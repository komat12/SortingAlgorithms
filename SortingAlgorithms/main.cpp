#include <iostream>
#include "class.h"

int main()
{
    Object order;

    order.configuration();
    order.input();
    order.solve();
    order.save();
}