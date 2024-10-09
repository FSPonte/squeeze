#ifndef _INCLUDE_HPP_
#define _INCLUDE_HPP_

#include <vector>
#include <fstream>

typedef char byte_t;
typedef unsigned long size_t;

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

#endif // _INCLUDE_HPP_
