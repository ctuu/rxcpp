#include "observable.h"

namespace rx
{

void observable::_subscribe(const subscriber &subscriber)
{
    __subscribe(subscriber);
}

observable::observable(const subscriber_function &subscriber) : __subscribe(subscriber) {}

void observable::subscribe(const subscriber &subscriber)
{
    _subscribe(subscriber);
}

} // namespace rx