#include <iostream>
#include "rx.h"

void func(int x)
{
    std::cout << "x: " << x << std::endl;
}

int main()
{
    auto funtor = rx::functor([](int i) -> int { return i * 2; });
    std::cout << funtor.call<int>(2) << std::endl;

    auto funtor2 = rx::functor(func);
    funtor2(2);
    
    return 0;
}