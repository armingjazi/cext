#pragma once

namespace all
{
    struct ILibrary
    {
        virtual void set(int variable) noexcept = 0;

        virtual int get() const noexcept = 0;
    };
}
