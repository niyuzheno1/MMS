#include "MMS/export.h"
using namespace MMS;
#include <functional>
#include <iostream>
using namespace std;

GenericMemoryManager * gmm;
SimpleMemoryManageInstance smmi;
SophiscatedMMInstance sommi;

char testMemory[10240];

void init(){
    gmm = &smmi;
    gmm->memInit();
    gmm = &sommi;
    sommi.setInit([](void ** mem){
        *mem = testMemory;
    });
    gmm->memInit();
}

using testType = function<bool()>;
bool test1(){
    int * a = (int*)gmm->allocate(sizeof(int));
    *a = 5;
    if(*a != 5){
        return false;
    }
    return true;
}
bool test2(){
    int * a = (int*)gmm->allocate(sizeof(int));
    *a = 5;
    int * b = (int*)gmm->reallocate(a, sizeof(int), sizeof(int));
    if(*b != 5){
        return false;
    }
    return true;
}
bool test3(){
    int * a = (int*)gmm->allocate(sizeof(int));
    *a = 5;
    int * b = (int*)gmm->reallocate(a, sizeof(int), sizeof(int) * 2);
    if(*b != 5){
        return false;
    }
    return true;
}
bool test4(){
    int * a = (int*)gmm->allocate(sizeof(int));
    *a = 5;
    int * b = (int*)gmm->reallocate(a, sizeof(int), 1, 2);
    if(*b != 5){
        return false;
    }
    return true;
}
bool test5(){
    int * a = (int*)gmm->allocate(sizeof(int));
    *a = 5;
    int * b = (int*)gmm->reallocate(a, sizeof(int), 1, 1);
    if(*b != 5){
        return false;
    }
    return true;
}

const testType tests[] = {test1, test2, test3, test4, test5};
GenericMemoryManager * gmmArray[] = {&smmi, &sommi};
int main(){
    init();
    for(int i = 0; i < 2; ++i){
        cout << "Testing on memory manager" << i  << endl;
        gmm = gmmArray[i];
        for(int j = 0; j < 5; ++j){
            if(!tests[j]()){
                cout << "Test " << j << " failed" << endl;
            }else{
                cout << "Test " << j << " passed" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}