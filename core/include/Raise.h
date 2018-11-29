#pragma once

#include <IEvent.h>

namespace ALL
{
    template<typename ...Arg>
    class Event;

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
}