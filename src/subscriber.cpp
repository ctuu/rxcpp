#include "subscriber.h"

namespace rx
{

void subscriber::complete() const
{
    _complete();
}

} // namespace rx
