#ifndef _COMPRESS_HPP_
#define _COMPRESS_HPP_

#include "include.hpp"

namespace encoding
{
    /**
     * @brief Run-length encoding
     * @param data Raw data
     * @return Compressed data
    */
    std::vector<byte_t> rle(const std::vector<byte_t>&) noexcept(true);
}

namespace decoding
{
    /**
     * @brief Run-length decoding
     * @param data Compressed data
     * @return Decompressed data
    */
    std::vector<byte_t> rle(const std::vector<byte_t>&) noexcept(true);
}

#include "../src/compression.ipp"

#endif // _COMPRESS_HPP_
