#pragma once

#include <cstddef>
#include <vector>

namespace all
{
    template<typename T>
    class AlignedArray
    {
    public:
        AlignedArray(size_t dim1, size_t dim2)
        : data_(dim1 * dim2)
        , pointers_(dim1)
        {
            for(size_t i = 0; i < dim1; ++i)
                pointers_[i] = &data_[i * dim2];
        }

        AlignedArray(const AlignedArray&) = delete;
        AlignedArray& operator=(const AlignedArray&) = delete;
        AlignedArray(AlignedArray&& other) = delete;
        AlignedArray& operator=(AlignedArray& other) = delete;

        const T* operator[] (size_t index) const
        {
            return pointers_[index];
        }

        T* operator[] (size_t index)
        {
            return pointers_[index];
        }

    private:
        std::vector<T> data_;
        std::vector<T*> pointers_;
    };
}