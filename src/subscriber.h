#ifndef CTUU_RX_SUBSCRIBER_H_
#define CTUU_RX_SUBSCRIBER_H_

#include "functor.h"

namespace rx
{

class subscriber
{
    functor _next, _error, _complete;

public:
    template <typename A, typename B = std::nullptr_t, typename C = std::nullptr_t>
    subscriber(A _next, B _error = nullptr, C _complete = nullptr) : _next(_next), _error(_error), _complete(_complete){};

    template <typename... Args>
    void next(Args... args) const
    {
        try
        {
            _next(args...);
        }
        catch (std::runtime_error e)
        {
        }
    }

    template <typename... Args>
    void error(Args... args) const
    {
        try
        {
            _error(args...);
        }
        catch (std::runtime_error e)
        {
        }
    }

    void complete() const;
};

}; // namespace rx
#endif