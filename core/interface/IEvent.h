#pragma once

#include <functional>
#include <memory>

namespace ALL
{
    template<typename ...Arg>
    struct IEvent
    {
        using callback = const std::function<void(Arg...)>;

        using callbackPtr = const std::shared_ptr<callback>&;

        virtual void operator+=(callbackPtr func) = 0;
    };
}