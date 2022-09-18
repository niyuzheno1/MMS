#include "SophiscatedMMInstance.h"
#include "assert.h"
using namespace MMS;

std::function<void(void **)> SophiscatedMMInstance::init;
void *SophiscatedMMInstance::wmem;

SophiscatedMMInstance::SophiscatedMMInstance(){
  
}
SophiscatedMMInstance::~SophiscatedMMInstance(){

}
void * SophiscatedMMInstance::allocate(size_t size){
    char * ret;
    walloc1d(&ret, static_cast<int>(size), &wmem);
    memset(ret, 0, size);
    return (void*)ret;
}
void * SophiscatedMMInstance::reallocate(void * pointer, size_t oldSize,  size_t size){
    char * ret;
    walloc1d(&ret, static_cast<int>(size), &wmem);
    memset(ret, 0, size);
    memcpy(ret, pointer, oldSize);
    return (void*)ret;
}
void * SophiscatedMMInstance::reallocate(void * pointer, size_t baseTypeSize, size_t oldSize, size_t newSize){
    char * ret;
    walloc1d(&ret, static_cast<int>(newSize * baseTypeSize), &wmem);
    memset(ret, 0, newSize * baseTypeSize);
    memcpy(ret, pointer, oldSize * baseTypeSize);
    return (void*)ret;
}
void SophiscatedMMInstance::deallocate(void ** pointer, size_t size) {

}
void SophiscatedMMInstance::deallocate(void ** pointer, size_t baseTypeSize, size_t size){
    
}
void SophiscatedMMInstance::setWorkingMemory(void * memory){
    wmem = memory;
}
void SophiscatedMMInstance::memInit() {
    assert(init != nullptr);
    if( wmem == nullptr){
        init(&wmem);
    }
}

void SophiscatedMMInstance::setInit(std::function<void(void **)> _init){
    init = _init;
}

void * SophiscatedMMInstance::getWmem() const{
    return wmem;
}