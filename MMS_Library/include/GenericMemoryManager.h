#pragma once

namespace MMS
{
    class GenericMemoryManager
    {
    public:
        virtual void *allocate(size_t size) = 0;
        virtual void *reallocate(void *pointer, size_t oldSize, size_t size) = 0;
        virtual void *reallocate(void *pointer, size_t baseTypeSize, size_t oldSize, size_t newSize) = 0;
        virtual void deallocate(void **pointer, size_t size) = 0;
        virtual void deallocate(void **pointer, size_t baseTypeSize, size_t size) = 0;
        virtual void memInit() = 0;
        // with Args
        template <typename T, typename... Args>
        T *newInstance(Args... args)
        {
            this->memInit();
            T tmp(args...);
            T *ret = (T *)this->allocate(sizeof(T));
            memcpy(ret, &tmp, sizeof(T));
            return ret;
        }
    };
}
