#include <iostream>
#include "rx.h"

int main()
{
    auto subject = rx::subject<int>();
    subject.subscribe([](int i) { std::cout << i * 2 << std::endl; });
    subject.next(3);
    subject.next(4);
    subject.next(5);
    return 0;
}