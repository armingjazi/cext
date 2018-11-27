#pragma once

#include <functional>
#include <set>

namespace ALL
{
    template<typename ...Arg>
    class Event;

    template<typename ...Arg>
    struct IEvent
    {
        using callback = const std::function<void(Arg...)>;

        using callbackPtr = std::weak_ptr<callback>;

        virtual void operator+=(callbackPtr func) = 0;
    };

    template<typename ...Arg>
    class Raise
    {
    public:
        Raise() = default;

        void operator()(Arg... args)
        {
            return t_(args...);
        };

        IEvent<Arg...>& create()
        {
            return t_;
        }

    private:
        Event<Arg...> t_;
    };

    template<typename ...Arg>
    class Event : public IEvent<Arg...>
    {
    public:

        Event & operator=(const Event&) = delete;

        void operator+=(typename IEvent<Arg...>::callbackPtr func) override
        {
            listeners_.emplace_back(func);
        }

    private:
        friend class Raise<Arg...>;

        Event() = default;

        Event(const Event&) = default;

        void operator()(Arg... args)
        {
            for(auto it = listeners_.begin(); it != listeners_.end();)
            {
                if (auto shared = it->lock())
                {
                    (*shared)(args...);
                    ++it;
                }
                else
                {
                    it = listeners_.erase(it);
                }
            }
        }

        std::vector<typename IEvent<Arg...>::callbackPtr> listeners_;
    };
}