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
    auto functor = rx::functor([](int i) -> int { return i * 2; });
    std::cout << functor.invoke<int>(4) << std::endl;
    std::cout << functor.operator()<int>(4) << std::endl;

    functor = func;
    functor(4);

    functor = nullptr;
    functor(1, 2, 3, 4); // nothing happen
    return 0;
}