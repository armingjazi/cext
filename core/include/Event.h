#pragma once

#include <functional>
#include <set>

#include <IEvent.h>
#include <Raise.h>

namespace ALL
{
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

        std::vector<std::weak_ptr<typename IEvent<Arg...>::callback> > listeners_;
    };
}