#ifndef _FILE_HANDLER_HPP_
#define _FILE_HANDLER_HPP_

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
#include "../src/file_handler.ipp"

#endif // _FILE_HANDLER_HPP_
