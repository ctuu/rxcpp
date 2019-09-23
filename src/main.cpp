#include <iostream>
#include <functional>
#include "rx.h"
void func(int i)
{
    std::cout << i << std::endl;
}
int main()
{
    auto observable = rx::observable([](rx::subscriber &subscriber) {
        subscriber.next(1);
        subscriber.next(2);
        subscriber.next(3);
        subscriber.complete();
    });
    observable.subscribe(rx::subscriber(
        func,
        nullptr,
        []() { std::cout << "complete" << std::endl; }));

    auto subject = rx::subject<int>();
    subject.subscribe([](int i) { std::cout << i * 2 << std::endl; });
    subject.next(3);
    subject.next(4);
    subject.next(5);

    auto behavior_subject = rx::behavior_subject<int>(20);
    behavior_subject.subscribe([](int i) { std::cout << i * 5 << std::endl; });
    behavior_subject.next(30);
    behavior_subject.next(40);
    behavior_subject.next(50);

    return 0;
}