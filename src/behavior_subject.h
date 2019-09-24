#ifndef CTUU_RX_BEHAVIOR_SUBJECT_H_
#define CTUU_RX_BEHAVIOR_SUBJECT_H_

#include "subject.h"

namespace rx
{

template <typename T>
class behavior_subject : public subject<T>
{
protected:
    T prev_value;

    void _subscribe(const subscriber &subscriber)
    {
        subject<T>::_subscribe(subscriber);
        subscriber.next(prev_value);
    }

public:
    behavior_subject(const T &value) : prev_value(value), subject<T>() {}

    T getValue()
    {
        return prev_value;
    }

    virtual void next(const T &value)
    {
        subject<T>::next(prev_value = value);
    }
};

}; // namespace rx
#endif