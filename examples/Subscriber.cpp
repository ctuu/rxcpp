#include <iostream>
#include "rx.h"

int main()
{
    auto a = rx::subscriber([](int i) { std::cout << i << std::endl; });
    a.next(3);
    a.next(4);
    return 0;
}