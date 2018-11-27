#pragma once

#include <functional>
#include <set>

namespace ALL
{

    template<typename T>
    class Event;

    template<typename T>
    struct IEvent
    {
        using callback = const std::function<void(T)>;

        using callbackPtr = std::weak_ptr<callback>;

        virtual void operator+=(callbackPtr func) = 0;
    };

    template<typename T>
    class Raise
    {
    public:
        Raise() = default;

        void operator()(T arg)
        {
            return t_(arg);
        };

        IEvent<T>& create()
        {
            return t_;
        }

    private:
        Event<T> t_;
    };

    template<typename T>
    class Event : public IEvent<T>
    {
    public:

        Event & operator=(const Event&) = delete;

        void operator+=(typename IEvent<T>::callbackPtr func) override
        {
            listeners_.emplace_back(func);
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

        std::vector<typename IEvent<T>::callbackPtr> listeners_;
    };
}