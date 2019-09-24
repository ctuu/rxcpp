#ifndef CTUU_RX_SUBJECT_H_
#define CTUU_RX_SUBJECT_H_

#include <any>
#include <list>
#include <memory>
#include "observable.h"

namespace rx
{
using subscri_list = std::list<subscriber>;

template <typename T>
class subject : public observable
{
private:
protected:
    std::any thrown_error = NULL;

    std::unique_ptr<subscri_list> subscribers;

    virtual void _subscribe(const subscriber &subscriber)
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");
        else if (is_stopped)
            subscriber.complete();
        else if (has_error)
            subscriber.error(thrown_error);
        else
            subscribers->emplace_back(subscriber);
    }

public:
    bool closed = false;
    bool has_error = false;
    bool is_stopped = false;
    
    subject()
    {
        subscribers = std::make_unique<subscri_list>();
    }

    virtual void next(const T &value)
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");

        if (!is_stopped)
        {
            for (auto e : *subscribers)
                e.next(value);
        }
    }

    virtual void error(const std::any &err)
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");

        has_error = true;
        thrown_error = err;
        is_stopped = true;
        for (auto e : *subscribers)
            e.error(err);

        subscribers->clear();
    }

    virtual void complete()
    {
        if (closed)
            throw std::runtime_error("UnsubscribedError");

        is_stopped = true;

        for (auto e : *subscribers)
            e.complete();

        subscribers->clear();
    }

    virtual void unsubscribe()
    {
        is_stopped = true;
        closed = true;
        subscribers = nullptr;
    }
};

}; // namespace rx
#endif