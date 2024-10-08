#ifndef _COMPRESS_HPP_
#define _COMPRESS_HPP_

#include "include.hpp"

/**
 * @brief Run-length encoding
 * @param dat Data vector
 * @return Compressed data vector
*/
std::vector<std::pair<byte_t, size_t>> rle(const std::vector<byte_t>&) noexcept(true);

#include "../src/compress.ipp"

#endif // _COMPRESS_HPP_
