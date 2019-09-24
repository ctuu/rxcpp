#include <iostream>
#include "rx.h"

int main()
{
    auto replay_subject = rx::replay_subject<int>(3);
    replay_subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

    replay_subject.next(1);
    replay_subject.next(2);
    replay_subject.next(3);
    replay_subject.next(4);

    replay_subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });
    
    replay_subject.next(5);
    return 0;
}