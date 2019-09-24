#include <iostream>
#include <any>
#include "rx.h"

int main()
{
    auto subject = rx::subject<int>();
    // subject.next(3);
    subject.subscribe(
        [](int i) { std::cout << "Next: " << i << std::endl; }, //next
        [](std::any err) { std::cout << "Error code: " << std::any_cast<int>(err) << std::endl; });
    subject.next(4);
    subject.next(5);
    subject.error(404);
    return 0;
}