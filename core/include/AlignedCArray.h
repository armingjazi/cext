#pragma once

#include <cstddef>
#include <vector>

namespace all
{
    template<typename T>
    class AlignedCArray
    {
    public:
        AlignedCArray(size_t dim1, size_t dim2)
        : dim1_(dim1)
        , dim2_(dim2)
        {
            data_ = malloc(sizeof(T*) * dim1_ + sizeof(T) * dim2_ * dim1_);
            array_ = static_cast<T**>(data_);
            const auto arrayData = reinterpret_cast<T*>(array_ + dim2_);

            for (size_t i = 0; i < dim1_; ++i)
                array_[i] = arrayData + dim2_ * i;

            for (size_t i = 0; i < dim1_; ++i)
                for (size_t j = 0; j < dim2_; ++j)
                    array_[i][j] = 0.0f;
        }

        const T* operator[] (size_t index) const
        {
            return array_[index];
        }

        T* operator[] (size_t index)
        {
            return array_[index];
        }

    private:
        void* data_ = nullptr;
        T** array_ = nullptr;
        size_t dim1_, dim2_;
    };
}