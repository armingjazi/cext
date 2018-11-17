#pragma once

#include "ILibrary.h"

namespace ALL
{
    class Library : public ILibrary
    {
    public:
        void set(int variable) noexcept override;

        int get() const noexcept override;

    private:
        int variable_ { 0 };
    };
}
