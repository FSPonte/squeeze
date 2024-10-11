#ifndef _INCLUDE_HPP_
#define _INCLUDE_HPP_

#include <cmath>
#include <vector>
#include <fstream>

typedef char byte_t;
typedef unsigned long size_t;

const size_t BUFFER_SIZE = 1024; // Maximum size of a buffer

// Process data type
enum process_t
{
    _invalid,
    _encode,
    _decode
};

// Algoritm data type
enum algorithm_t
{
    _none,
    _rle        // Run-length enconding
};

// Buffer memory map data type
union buffer_mmap
{
    size_t size;
    byte_t byte[sizeof(size_t)];
};

#endif // _INCLUDE_HPP_
