#pragma once
#include "GenericMemoryManager.h"
namespace MMS
{
    class SimpleMemoryManageInstance : public GenericMemoryManager
    {
    public:
        SimpleMemoryManageInstance();
        ~SimpleMemoryManageInstance();
        void * allocate(size_t size) override;
        void * reallocate(void * pointer, size_t oldSize, size_t size) override;
        void * reallocate(void * pointer, size_t baseTypeSize, size_t oldSize, size_t newSize) override;
        void deallocate(void ** pointer, size_t size) override;
        void deallocate(void ** pointer, size_t baseTypeSize, size_t size) override;
        void memInit() override;
    };
}