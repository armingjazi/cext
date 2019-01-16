
#include "Library.h"

namespace all
{
    void Library::set(int variable) noexcept
    {
        variable_ = variable;
    }

    int Library::get() const noexcept
    {
        return variable_;
    }
}
