#include <iostream>
#include "rx.h"

void next_func(int i);

int main()
{
    rx::of({1, 3, 5, 7})
        .subscribe(
            next_func,
            nullptr, //error_func
            []() { std::cout << "Completed" << std::endl; });
    return 0;
}

void next_func(int i)
{
    std::cout << "Next:" << i << std::endl;
}