#ifndef _UTILS_IPP_
#define _UTILS_IPP_

namespace utils
{
    std::vector<double> dct(const std::vector<double>& data)
    {
        size_t size = data.size();
        std::vector<double> result(size);

        // Precompute normalization factor for k=0
        double
            coef_0 = std::sqrt(1.0 / size), // Coefficient of index 0
            coef_n = std::sqrt(2.0 / size), // Coefficient of index n
            sum;

        // Loop over each DCT coefficient k
        for (size_t i = 0; i < size; ++i)
        {
            sum = 0.0;

            // Sum the contributions of each input point n
            for (size_t j = 0; j < size; ++j)
                sum += data[j] * std::cos(PI * i * (j + 0.5) / size);

            // Apply normalization factor
            if (i == 0)
                result[i] = coef_0 * sum;  // Special case for k=0
            else
                result[i] = coef_n * sum;  // For k > 0
        }

        return result;
    }
}

#endif // _UTILS_IPP_