#include "functor.h"

namespace functor
{

std::nullptr_t wrap(const std::nullptr_t &fn)
{
    return fn;
}

}; // namespace functor
