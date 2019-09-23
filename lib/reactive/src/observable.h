#ifndef CTUU_RX_OBSERVABLE_H_
#define CTUU_RX_OBSERVABLE_H_

#include <functional>
#include "functor.h"
#include "subscriber.h"

namespace rx
{

class observable
{
private:
    std::function<void(subscriber &)> __subscribe;

protected:
    virtual void _subscribe(subscriber);

public:
    observable() = default;

    observable(const std::function<void(subscriber &)> &);

    void subscribe(subscriber);

    template <typename A, typename B = std::nullptr_t, typename C = std::nullptr_t>
    void subscribe(const A &_next = nullptr, const B &_error = nullptr, const C &_complete = nullptr)
    {
        auto e = subscriber(_next, _error, _complete);
        this->subscribe(e);
    }
};

}; // namespace rx
#endif