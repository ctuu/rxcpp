#include <iostream>
#include "rx.h"

int main()
{
    auto subscriber = rx::subscriber(
        [](int i) { std::cout << "Next: " << i << std::endl; },
        nullptr,
        []() { std::cout << "Completed" << std::endl; });
    subscriber.next(3);
    subscriber.next(4);
    subscriber.error(); // nothing happen
    subscriber.complete();
    return 0;
}