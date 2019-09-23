#ifndef CTUU_FUNCTOR_H_
#define CTUU_FUNCTOR_H_

#include <any>
#include <functional>
#include <type_traits>

// from http://www.cplusplus.com/forum/general/223816/ @JLBorges
namespace functor::detail
{

template <typename T>
struct deduce_type;

template <typename RETURN_TYPE, typename CLASS_TYPE, typename... Args>
struct deduce_type<RETURN_TYPE (CLASS_TYPE::*)(Args...) const>
{
    using type = std::function<RETURN_TYPE(Args...)>;
};

}; // namespace functor::detail

namespace functor
{

std::nullptr_t wrap(const std::nullptr_t &fn);

template <typename RETURN_TYPE, typename... Args> // std::function
auto wrap(const std::function<RETURN_TYPE(Args...)> &fn)
{
    return fn;
}
template <typename RETURN_TYPE, typename... Args> // function pointer
auto wrap(RETURN_TYPE (*fn)(Args...))
{
    return std::function<RETURN_TYPE(Args...)>(fn);
}

template <typename CLOSURE>
auto wrap(const CLOSURE &fn) // lambda expression
{
    return typename detail::deduce_type<decltype(&CLOSURE::operator())>::type(fn);
}

class functor
{
private:
    std::any func;

public:
    template <typename T>
    functor(const T &_func)
    {
        this->func = wrap(_func);
    }

    template <typename RETURN_TYPE = void, typename... Args>
    auto operator()(Args... args) const
    {
        return std::invoke(std::any_cast<std::function<RETURN_TYPE(Args...)>>(func), args...);
    }

    template <typename RETURN_TYPE = void, typename... Args>
    auto call(Args... args) const
    {
        return std::invoke(std::any_cast<std::function<RETURN_TYPE(Args...)>>(func), args...);
    }
};

}; // namespace functor
#endif