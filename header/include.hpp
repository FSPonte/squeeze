#ifndef _INCLUDE_HPP_
#define _INCLUDE_HPP_

#include <vector>
#include <fstream>

typedef char byte_t;
typedef unsigned long size_t;

const size_t BUFFER_SIZE = 1024;

enum process_t
{
    _invalid,
    _compress,
    _decompress
};

enum algorithm_t
{
    _none,
    _rle
};

union buffer_mmap
{
    size_t size;
    byte_t byte[sizeof(size_t)];
};

#endif // _INCLUDE_HPP_
