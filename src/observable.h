#ifndef CTUU_RX_OBSERVABLE_H_
#define CTUU_RX_OBSERVABLE_H_

#include <functional>
#include "subscriber.h"

namespace rx
{

using subscriber_function = std::function<void(const subscriber &)>;

class observable
{
private:
    subscriber_function __subscribe;

protected:
    virtual void _subscribe(const subscriber &);

public:
    observable() = default;

    observable(const subscriber_function &subscriber);

    void subscribe(const subscriber &);

    template <typename A, typename B = std::nullptr_t, typename C = std::nullptr_t>
    void subscribe(const A &_next = nullptr, const B &_error = nullptr, const C &_complete = nullptr)
    {
        auto e = subscriber(_next, _error, _complete);
        this->subscribe(e);
    }
};

}; // namespace rx
#endif