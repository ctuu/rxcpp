#ifndef CTUU_RX_SUBJECT_H_
#define CTUU_RX_SUBJECT_H_

#include <list>
#include "observable.h"

namespace rx
{

template <typename T>
class subject : public observable
{
private:
protected:
    std::list<subscriber> subscribers;
    
    virtual void _subscribe(const subscriber &subscriber)
    {
        subscribers.push_back(subscriber);
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