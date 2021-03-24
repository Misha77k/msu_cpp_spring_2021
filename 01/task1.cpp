#include<iostream>

//template <class T>


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
            std::cout << "Delete last mem" << std::endl;
        }
        if (maxSize > 0) {
            start = new char[maxSize];
            totalSize = maxSize;
            offset = 0;
        }
        else {
            std::cout << "Wrong Dimension" << std::endl;
            start = nullptr;
            totalSize = 0;
            offset = 0;
        }
    }

    char* alloc(int size)
    {
        if(size < 0) {
            std::cout << "Wrong Size" << std::endl;
            return nullptr;
        }
        if(!start)
            return nullptr;
        std::cout << "Before" << std::endl;
        std::cout << static_cast<int>(offset) << std::endl;
        if((offset + size) <= totalSize) {
            offset = offset + size;
            std::cout << "After" << std::endl;
            std::cout << static_cast<int>(offset) << std::endl;
            return start + offset - size;
        }
        else {
            std::cout << "Not Enough Mem" << std::endl;
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

