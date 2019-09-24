#include <iostream>
#include "rx.h"

void func(int i);

int main()
{
    auto a = [](const rx::subscriber &subscriber) {
        subscriber.next(1);
        subscriber.next(2);
        subscriber.next(3);
        subscriber.complete();
    };
    
    auto observable = rx::observable(a);

    observable.subscribe(rx::subscriber(
        func,
        nullptr,
        []() { std::cout << "complete" << std::endl; }));
    return 0;
}

void func(int i)
{
    std::cout << i << std::endl;
}