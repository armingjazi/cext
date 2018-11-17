
#include "Library.h"

namespace ALL
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
