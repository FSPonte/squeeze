#ifndef _UTILS_HPP_
#define _UTILS_HPP_

// Dependencies
#include "include.hpp"

/**
 * @brief Print a error message
 * @param msg Message
 * @throw Error message is a null pointer
*/
void err_msg(const char[]) noexcept(false);

/**
 * @brief Print a exception message
 * @param msg Message
 * @throw Exception message is a null pointer
*/
void exc_msg(const char[]) noexcept(false);

/**
 * @brief Get process
 * @param arg Argument
 * @return Process type
 * @throw Process type string is a null pointer
*/
process_t get_process_type(const char[]) noexcept(false);

/**
 * @brief Get algorithm
 * @param arg Argument
 * @return Compression type
 * @throw Algorithm type string is a null pointer
*/
algorithm_t get_algorithm_type(const char[]) noexcept(false);

// Implementation file
#include "../src/utils.ipp"

#endif // _UTILS_HPP_
