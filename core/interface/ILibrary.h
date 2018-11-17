#pragma once

namespace ALL
{
    class ILibrary
    {
    public:
        virtual void set(int variable) noexcept = 0;

        virtual int get() const noexcept = 0;
    };
}
