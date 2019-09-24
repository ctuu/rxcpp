#include <iostream>
#include "rx.h"

int main()
{
    auto subject = rx::behavior_subject<int>(0);
    subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

    subject.next(1);
    subject.next(2);

    subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });

    subject.next(3);
    return 0;
}