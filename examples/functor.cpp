#include <iostream>
#include <typeinfo>
#include "rx.h"

class A
{
public:
    int x;

    A(int e)
    {
        x = e * 3;
    }
};

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
    
    auto functor = rx::functor([](int i) -> A { return A(i); });
    std::cout << functor.call<A>(2).x << std::endl;
    return 0;
}