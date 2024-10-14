#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "include.hpp"

namespace utils
{
    /**
     * @brief Discrete cosine transform
     * @param data Data vector
     * @return Coefficients
    */
    std::vector<double> dct(const std::vector<double>&);
}

// Implementation file
#include "../src/utils.ipp"

#endif // _UTILS_HPP_
