#ifndef CTUU_RX_OF_H_
#define CTUU_RX_OF_H_

#include <initializer_list>
#include "observable.h"

namespace rx
{

template <typename T>
observable of(std::initializer_list<T> &&list)
{
    return observable([list](auto &subscriber) {
        for (auto i : list)
            subscriber.next(i);
        subscriber.complete();
    });
}

} // namespace rx
#endif