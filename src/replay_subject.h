#ifndef CTUU_RX_REPLAY_SUBJECT_H_
#define CTUU_RX_REPLAY_SUBJECT_H_

#include <list>
#include "subject.h"

namespace rx
{

template <typename T>
class replay_subject : public subject<T>
{
protected:
    int buffer_size;
    std::list<T> events;

    void _subscribe(const subscriber &subscriber)
    {
        if (this->closed)
            throw std::runtime_error("UnsubscribedError");
        else if (!this->is_stopped && !this->has_error)
            this->subscribers->emplace_back(subscriber);

        for (auto i : events)
            subscriber.next(i);

        if (this->has_error)
            subscriber.error(this->thrown_error);
        else if (this->is_stopped)
            subscriber.complete();
    }

    void trim_buffer()
    {
        int len = events.size();
        while(len > buffer_size)
        {
            events.pop_front();
            --len;
        }
    }

public:
    replay_subject(const int &_buffer_size) : subject<T>()
    {
        buffer_size = _buffer_size < 1 ? 1 : _buffer_size;
    }

    virtual void next(const T &value)
    {
        events.emplace_back(value);
        trim_buffer();
        subject<T>::next(value);
    }
};

} // namespace rx
#endif