#pragma once

#include "ILibrary.h"

namespace all
{
    /*
     * NOTE: not for use, this is only to ensure code style
     */
    class Library : public ILibrary
    {
    public:
        void set(int variable) noexcept override;

        int get() const noexcept override;

    private:
        int variable_ { 0 };
    };
}
