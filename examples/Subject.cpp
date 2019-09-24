#include <iostream>
#include <any>
#include "rx.h"

int main()
{
    auto subject = rx::subject<int>();
    
    subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });
    subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });
    subject.subscribe(
        [](int i) { std::cout << "observerC: " << i << std::endl; },
        [](std::any err) { std::cout << "Error code: " << std::any_cast<int>(err) << std::endl; });

    subject.next(1);
    subject.next(2);
    subject.error(404);
    return 0;
}