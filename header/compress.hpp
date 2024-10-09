#ifndef _COMPRESS_HPP_
#define _COMPRESS_HPP_

#include "include.hpp"

/**
 * @brief Run-length encoding
 * @param data Raw data
 * @return Compressed data
*/
std::vector<byte_t> rle(const std::vector<byte_t>&) noexcept(true);

#include "../src/compress.ipp"

#endif // _COMPRESS_HPP_
