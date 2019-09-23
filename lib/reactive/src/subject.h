#ifndef CTUU_RX_SUBJECT_H_
#define CTUU_RX_SUBJECT_H_

#include <list>
#include <iostream>
#include "observable.h"

namespace rx
{

template <typename T>
class subject : public observable
{
private:
protected:
    std::list<subscriber> subscribers;
    void _subscribe(subscriber _subscriber)
    {
        subscribers.push_back(_subscriber);
    }

public:
    subject() = default;
    virtual void next(const T &value)
    {
        for (auto e : subscribers)
            e.next(value);
    }
};

}; // namespace rx
#endif