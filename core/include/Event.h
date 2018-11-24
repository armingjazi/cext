#pragma once

#include <functional>
#include <set>

namespace ALL
{
    template<typename T>
    class Event;

    template<typename T>
    class Raise
    {
    public:
        Raise() = default;

        void operator()(T arg)
        {
            return t_(arg);
        };

        Event<T>& create()
        {
            return t_;
        }

    private:
        Event<T> t_;
    };

    template<typename T>
    class Event
    {
    public:
        using callback = const std::function<void(T)>;

        Event & operator=(const Event&) = delete;

        void operator+=(std::shared_ptr<callback> func)
        {
            listeners_.push_back(func);
        }

    private:
        friend class Raise<T>;

        Event() = default;

        Event(const Event&) = default;

        void operator()(T arg)
        {
            for(auto it = listeners_.begin(); it != listeners_.end();)
            {
                if (auto shared = it->lock())
                {
                    (*shared)(arg);
                    ++it;
                }
                else
                {
                    it = listeners_.erase(it);
                }
            }
        }

        std::vector<std::weak_ptr<callback>> listeners_;
    };
}