#ifndef _DATA_FILE_HPP_
#define _DATA_FILE_HPP_

#include "include.hpp"

/**
 * @brief Load file
 * @param name File name
 * @return Pointer to file object
 * @throw File did not open
 * @throw File is not good
*/
std::vector<byte_t> load(const std::string&) noexcept(false);

/**
 * @brief Save file (rle)
 * @param data Data
 * @param name File name
 * @throw File did not open
 * @throw File is not good
*/
void save(const std::vector<byte_t>&, const std::string&) noexcept(false);

// Implementation file
#include "../src/data_file.ipp"

#endif // _DATA_FILE_HPP_
