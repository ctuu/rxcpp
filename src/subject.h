#ifndef CTUU_RX_SUBJECT_H_
#define CTUU_RX_SUBJECT_H_

#include <memory>
#include <list>
#include "observable.h"

namespace rx
{
using subscri_list = std::list<subscriber>;

template <typename T>
class subject : public observable
{
private:
protected:
    bool closed = false;
    bool isStopped = false;

    std::unique_ptr<subscri_list>subscribers;

    virtual void _subscribe(const subscriber &subscriber)
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");
        else if (isStopped)
            subscriber.complete();
        else
            subscribers->emplace_back(subscriber);
    }

public:
    subject()
    {
        subscribers = std::make_unique<subscri_list>();
    }

    virtual void next(const T &value)
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");

        if (!isStopped)
        {
            for (auto e : *subscribers)
                e.next(value);
        }
    }

    virtual void error(const T &err)
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");

        isStopped = true;

        if (!isStopped)
        {
            for (auto e : *subscribers)
                e.error(err);
        }

        subscribers->clear();
    }

    virtual void complete()
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");

        isStopped = true;

        if (!isStopped)
        {
            for (auto e : *subscribers)
                e.complete();
        }

        subscribers->clear();
    }

    virtual void unsubscribe()
    {
        isStopped = true;
        closed = true;
        subscribers->clear();
    }
};

}; // namespace rx
#endif