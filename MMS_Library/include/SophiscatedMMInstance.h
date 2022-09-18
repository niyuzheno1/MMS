#pragma once
// credit to LayCurse for this code http://rsujskf.s602.xrea.com/files/clay.html

#include "GenericMemoryManager.h"
#include <functional>
namespace MMS
{
    class SophiscatedMMInstance : public GenericMemoryManager
    {
    public:
        SophiscatedMMInstance();
        ~SophiscatedMMInstance();
        virtual void *allocate(size_t size);
        virtual void *reallocate(void *pointer, size_t oldSize, size_t size);
        virtual void *reallocate(void *pointer, size_t baseTypeSize, size_t oldSize, size_t newSize);
        virtual void deallocate(void **pointer, size_t size) ;
        virtual void deallocate(void **pointer, size_t baseTypeSize, size_t size) ;
        virtual void setWorkingMemory(void *memory);
        virtual void memInit() ;
        template <class T>
        static void walloc1d(T **arr, int x, void **mem = &wmem)
        {
            if (init != nullptr && *mem == nullptr)
            { // see functional:1195
                init(mem);
            }
            static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
            (*mem) = (void *)(((char *)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
            (*arr) = (T *)(*mem);
            (*mem) = ((*arr) + x);
        }
        virtual void setInit(std::function<void(void **)> _init);
        virtual void * getWmem() const;
    protected:
        static std::function<void(void **)> init;
        static void *wmem;
    };
}
