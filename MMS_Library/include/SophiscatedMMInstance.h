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
        void *allocate(size_t size) override;
        void *reallocate(void *pointer, size_t oldSize, size_t size) override;
        void *reallocate(void *pointer, size_t baseTypeSize, size_t oldSize, size_t newSize) override;
        void deallocate(void **pointer, size_t size) override;
        void deallocate(void **pointer, size_t baseTypeSize, size_t size) override;
        void setWorkingMemory(void *memory);
        void memInit() override;
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
        void setInit(std::function<void(void **)> _init);
        void * getWmem() const;
    protected:
        static std::function<void(void **)> init;
        static void *wmem;
    };
}
