#include <iostream>
#include "rx.h"

int main()
{
    auto behavior_subject = rx::behavior_subject<int>(20);
    behavior_subject.next(30);
    behavior_subject.subscribe([](int i) { std::cout << "Next: " << i << std::endl; });
    behavior_subject.next(40);
    behavior_subject.next(50);

    return 0;
}