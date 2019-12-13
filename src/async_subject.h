#ifndef CTUU_RX_ASYNC_SUBJECT_H_
#define CTUU_RX_ASYNC_SUBJECT_H_

#include <list>
#include "subject.h"

namespace rx
{

template <typename T>
class async_subject : public subject<T>
{
protected:
    T value;

    void _subscribe(const subscriber &subscriber)
    {

        if (this->has_error)
            subscriber.error(this->thrown_error);
        else if (has_completed && has_next)
        {
            subscriber.next(value);
            subscriber.complete();
        }
        else
            subject<T>::_subscribe(subscriber);
    }

public:
    bool has_next = false;
    bool has_completed = false;
    virtual void next(const T &value)
    {
        if (!has_completed)
        {
            this->value = value;
            has_next = true;
        }
    }

    virtual void error(const std::any &err)
    {
        if (!has_completed)
            subject<T>::error(err);
    }

    virtual void complete()
    {
        has_completed = true;

        if (has_next)
            subject<T>::next(value);

        subject<T>::complete();
    }
};

} // namespace rx
#endif