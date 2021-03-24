#include<iostream>


class Allocator
{
public:
    
    char* start;
    size_t totalSize;
    size_t offset;

    Allocator()
    {
        start = nullptr;
        totalSize = 0;
        offset = 0;
    }

    void makeAllocator(int maxSize)
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

    char* alloc(int size)
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

    void reset()
    {
        if(start) {
            offset = 0;
        }
    }

    ~Allocator()
    {
        if(totalSize == 0) {
            delete start;
        }
        if(start) {
            delete[] start;
            totalSize = 0;
            offset = 0;
        }
    }
};
