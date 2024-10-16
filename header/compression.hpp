#ifndef _COMPRESSION_HPP_
#define _COMPRESSION_HPP_

#include "include.hpp"

namespace encoding
{
    /**
     * @brief Run-length encoding
     * @param data Raw data
     * @return Compressed data
    */
    std::vector<byte_t> rle(const std::vector<byte_t>&) noexcept(true);

    /**
     * @brief Discrete cosine transform
     * @param data Raw data
     * @return Compressed data
    */
    std::vector<byte_t> dct(const std::vector<byte_t>&) noexcept(true);
}

namespace decoding
{
    /**
     * @brief Run-length decoding
     * @param data Compressed data
     * @return Decompressed data
    */
    std::vector<byte_t> rle(const std::vector<byte_t>&) noexcept(true);

    /**
     * @brief Discrete cosine transform
     * @param data Compressed data
     * @return Decompressed data
    */
    std::vector<byte_t> dct(const std::vector<byte_t>&) noexcept(true);
}

#include "../src/compression.ipp"

#endif // _COMPRESSION_HPP_
