#include <iostream>
#include "rx.h"

int main()
{
    auto subject = rx::async_subject<int>();
    subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

    subject.next(1);
    subject.next(2);

    subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });

    subject.next(3);

    subject.complete();
    return 0;
}