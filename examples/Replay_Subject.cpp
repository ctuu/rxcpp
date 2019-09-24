#include <iostream>
#include "rx.h"

int main()
{
    auto subject = rx::replay_subject<int>(3);
    subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

    subject.next(1);
    subject.next(2);
    subject.next(3);
    subject.next(4);

    subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });
    
    subject.next(5);
    return 0;
}