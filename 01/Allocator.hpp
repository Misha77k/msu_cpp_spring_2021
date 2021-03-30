#ifndef HPP_ALLOCATOR
#define HPP_ALLOCATOR

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

#endif
