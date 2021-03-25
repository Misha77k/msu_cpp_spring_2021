#include<iostream>

class Allocator
{
    public:
        char* start;
        size_t offset;
        size_t totalSize;
        
        Allocator();
        void makeAllocator(size_t maxSize);
        char* alloc(size_t size);
        void reset();
        ~Allocator();
};

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
