#include <iostream>
#include "rx.h"

int main()
{
    auto subject = rx::subject<int>();
    subject.next(3);
    subject.subscribe([](int i) { std::cout << "Next: " << i << std::endl; });
    subject.next(4);
    subject.next(5);
    return 0;
}