#include "Allocator.hpp"
#include <iostream>

Allocator::Allocator()
{
    start = nullptr;
    offset = 0;
    totalSize = 0;
}

void Allocator::makeAllocator(size_t maxSize)
{
    if (start) {
        delete[] start;
    }
    if (maxSize > 0) {
        start = new char[maxSize];
        totalSize = maxSize;
        offset = 0;
    }
    else {
        start = nullptr;
        totalSize = 0;
        offset = 0;
    }
}

char* Allocator::alloc(size_t size)
{
    if(size < 0) {
        return nullptr;
    }
    if(!start) {
        return nullptr;
    }
    if((offset + size) <= totalSize) {
        offset = offset + size;
        return start + offset - size;
    }
    else {
        return nullptr;
    }
}

void Allocator::reset()
{
    if (start) {
        offset = 0;
    }
}

Allocator::~Allocator()
{
    if (totalSize == 0) {
        delete start;
    }
    if (start) {
        delete[] start;
        totalSize = 0;
        offset = 0;
    }
}
