An attempt at Reactive Programming for C++ 17

Inspired by [RxJS](https://rxjs.dev)


## build examples

``` c++
cd build
cmake && make
```

executable examples in `bin/examples`


``` c++
namespace rx {
    class functor;
    class subscriber;
    class observable;
    class subject<T>;
    class behavior_subject<T>;
    class replay_subject<T>;
    class async_subject<T>;
}
```
## rx::functor

``` c++
class rx::functor {
    functor(std::function | Lambda Expression | Pointer Function);
    T operator<T>(...arg);
    T invoke<T>(...arg);
}
```

### Example:

``` c++
#include <iostream>
#include "rx.h"

void func(int x)
{
    std::cout << "x: " << x << std::endl;
}

auto functor = rx::functor([](int i) -> int { return i * 2; });
std::cout << functor.invoke<int>(4) << std::endl;
std::cout << functor.operator()<int>(4) << std::endl;

functor = func;
functor(4);

functor = nullptr;
functor(1,2,3,4); // nothing happen

// Result:
// 8
// 8
// x: 4

```

---

## rx::subscriber

``` c++
class rx::subscriber {
    subscriber(
        rx::functor next,  
        rx::functor error?,
        rx::functor complete?
    );
    void next(...arg);
    void error(...arg);
    void complete(); 
}
```

### Example:

``` c++
#include <iostream>
#include "rx.h"

auto subscriber = rx::subscriber(
    [](int i) { std::cout << "Next: " << i << std::endl; },
    nullptr,
    [](){ std::cout << "Completed" << std::endl;}
    );
subscriber.next(3);
subscriber.next(4);
subscriber.error(); // nothing happen
subscriber.complete();

// Result:
// Next: 3
// Next: 4
// Completed
```

---


## rx::observable

``` c++
class rx::observable {
    observable(std::function<void(const subscriber &)>);
    void subscribe(const subscriber &);
    void subscribe(
        rx::functor next,  
        rx::functor error?,
        rx::functor complete?
    );
}
```

### Example:

``` c++
#include <iostream>
#include "rx.h"

void next_func(int i)
{
    std::cout << "Next:" << i << std::endl;
}

auto observable = rx::observable(
    [](const rx::subscriber &subscriber) {
        subscriber.next(1);
        subscriber.next(2);
        subscriber.next(3);
        subscriber.complete();
    }
);

observable.subscribe(rx::subscriber(
    next_func,
    nullptr, //error_func
    []() { std::cout << "Completed" << std::endl; })
);

// Result:
// Next:1
// Next:2
// Next:3
// Completed
```

---

## rx::subject

``` c++
class rx::subject<T>: rx::observable {
    subject<T>();
    bool closed = false;
    bool has_error = false;
    bool is_stopped = false;
    void next(...arg);
    void error(std::any err);
    void complete();
}
```

### Example: 
``` c++
#include <any>
#include <iostream>
#include "rx.h"

auto subject = rx::subject<int>();

subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });
subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });
subject.subscribe(
    [](int i) { std::cout << "observerC: " << i << std::endl; },
    [](std::any err) { std::cout << "Error code: " << std::any_cast<int>(err) << std::endl; });

subject.next(1);
subject.next(2);
subject.error(404);

// Result:
// observerA: 1
// observerB: 1
// observerC: 1
// observerA: 2
// observerB: 2
// observerC: 2
// Error code: 404
```

---

## rx::behavior_subject

``` c++
class rx::behavior_subject<T>: rx::subject<T> {
    behavior_subject<T>(T init_value);
    T get_value();
}
```

### Example:

``` c++
#include <iostream>
#include "rx.h"

auto subject = rx::behavior_subject<int>(0);
subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

subject.next(1);
subject.next(2);

subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });

subject.next(3);

// Result:
// observerA: 0
// observerA: 1
// observerA: 2
// observerB: 2
// observerA: 3
// observerB: 3
```

---

## rx::replay_subject

``` c++
class rx::replay_subject<T>: subject<T> {
    replay_subject<T>(int buffer_size);
}
```

### Example:

``` c++
#include <iostream>
#include "rx.h"

auto subject = rx::replay_subject<int>(3);
subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

subject.next(1);
subject.next(2);
subject.next(3);
subject.next(4);

subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });

subject.next(5);

// Result:
// observerA: 1
// observerA: 2
// observerA: 3
// observerA: 4
// observerB: 2
// observerB: 3
// observerB: 4
// observerA: 5
// observerB: 5
```

---

## rx::async_subject

``` c++
class rx::async_subject<T>: subject<T> {
    async_subject<T>();
    bool has_next = false;
    bool has_completed = false;
}
```

### Example:

``` c++
#include <iostream>
#include "rx.h"

auto subject = rx::async_subject<int>();
subject.subscribe([](int i) { std::cout << "observerA: " << i << std::endl; });

subject.next(1);
subject.next(2);

subject.subscribe([](int i) { std::cout << "observerB: " << i << std::endl; });

subject.next(3);

subject.complete();

// Result:
// observerA: 3
// observerB: 3
```
