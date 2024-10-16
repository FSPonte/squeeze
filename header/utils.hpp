#ifndef _UTILS_HPP_
#define _UTILS_HPP_

// Dependencies
#include "include.hpp"

/**
 * @brief Print a error message
 * @param msg Message
*/
void err_msg(const char[]) noexcept(true);

/**
 * @brief Print a exception message
 * @param msg Message
*/
void exc_msg(const char[]) noexcept(true);

/**
 * @brief Get process
 * @param arg Argument
 * @return Process type
*/
process_t get_process_type(const char[]) noexcept(true);

/**
 * @brief Get algorithm
 * @param arg Argument
 * @return Compression type
*/
algorithm_t get_algorithm_type(const char[]) noexcept(true);

// Implementation file
#include "../src/utils.ipp"

#endif // _UTILS_HPP_
