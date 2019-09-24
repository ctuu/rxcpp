#include <iostream>
#include "rx.h"

void next_func(int i);

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
        next_func,
        nullptr, //error_func
        []() { std::cout << "Completed" << std::endl; }));
    return 0;
}

void next_func(int i)
{
    std::cout << "Next:" << i << std::endl;
}