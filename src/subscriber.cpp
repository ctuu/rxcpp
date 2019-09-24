#include "subscriber.h"

namespace rx
{

void subscriber::complete() const
{
    try
    {
        _complete();
    }
    catch (std::runtime_error e)
    {
    }
}

}; // namespace rx
