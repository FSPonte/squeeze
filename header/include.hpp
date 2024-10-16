#ifndef _INCLUDE_HPP_
#define _INCLUDE_HPP_

#include <cstring>
#include <cmath>
#include <vector>
#include <fstream>

typedef char byte_t;
typedef unsigned long size_t;
typedef std::vector<byte_t> (*func_ptr)(const std::vector<byte_t>&) noexcept(true);

const size_t BUFFER_SIZE = 1024; // Maximum size of a buffer
const double PI = 3.14159265358979323846; // Pi constant

// Process data type
enum process_t
{
    _invalid = -1,
    _encode,
    _decode
};

// Algoritm data type
enum algorithm_t
{
    _none = -1,
    _rle = 0,       // Run-length enconding
    _dct = 1,       // Discrete cosine transform

    size            // Number of enumerators
};

// Buffer memory map data type
union buffer_mmap
{
    size_t size;
    byte_t byte[sizeof(size_t)];
};

#endif // _INCLUDE_HPP_
