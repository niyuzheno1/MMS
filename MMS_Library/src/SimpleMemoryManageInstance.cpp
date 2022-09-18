#include "SimpleMemoryManageInstance.h"
using namespace MMS;
#include <stdlib.h>
SimpleMemoryManageInstance::SimpleMemoryManageInstance(){

}
SimpleMemoryManageInstance::~SimpleMemoryManageInstance(){

}
void * SimpleMemoryManageInstance::allocate(size_t size){
    return malloc(size);
}
void * SimpleMemoryManageInstance::reallocate(void * pointer, size_t oldSize, size_t size){
    return realloc(pointer, size);
}
void * SimpleMemoryManageInstance::reallocate(void * pointer, size_t baseTypeSize, size_t oldSize, size_t newSize){
    return realloc(pointer, newSize * baseTypeSize);
}
void SimpleMemoryManageInstance::deallocate(void ** pointer, size_t size){
    free(*pointer);
    *pointer = nullptr;
}
void SimpleMemoryManageInstance::deallocate(void ** pointer, size_t baseTypeSize, size_t size){
    free(*pointer);
    *pointer = nullptr;
}
void SimpleMemoryManageInstance::memInit(){

}