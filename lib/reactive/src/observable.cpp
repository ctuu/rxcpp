#include "observable.h"

namespace rx
{

void observable::_subscribe(subscriber subscriber)
{
    __subscribe(subscriber);
}

observable::observable(const std::function<void(subscriber &)> &subscriber) : __subscribe(subscriber) {}

void observable::subscribe(const subscriber &_subscriber)
{
    _subscribe(_subscriber);
}

}; // namespace rx