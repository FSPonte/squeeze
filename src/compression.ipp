#ifndef _COMPRESSION_IPP_
#define _COMPRESSION_IPP_

namespace encoding
{
    std::vector<byte_t> rle(const std::vector<byte_t>& data) noexcept(true)
    {
        size_t size = data.size();
        std::vector<byte_t> result;
        byte_t count;

        for (size_t i = 0; i < size; ++i)
        {
            count = 1;

            while (i < size - 1 && data[i] == data[i + 1]) 
            {
                ++count;
                ++i;

                if (count == std::pow(2, sizeof(size_t)))
                {
                    result.push_back(data[i]);
                    result.push_back(count);
                    count = 1;
                }
            }

            result.push_back(data[i]);
            result.push_back(count);
        }

        return result;
    }

    std::vector<byte_t> dct(const std::vector<byte_t>& data) noexcept(true)
    {
        size_t size = data.size();
        std::vector<byte_t> result(size);

        // Precompute normalization factor for k=0
        byte_t
            coef_0 = std::sqrt(1.0 / size), // Coefficient of index 0
            coef_n = std::sqrt(2.0 / size), // Coefficient of index n
            sum;

        // Loop over each DCT coefficient k
        for (size_t i = 0; i < size; ++i)
        {
            sum = 0;

            // Sum the contributions of each input point n
            for (size_t j = 0; j < size; ++j)
                sum += data[j] * static_cast<byte_t>(std::cos(PI * i * (j + 0.5) / size));

            // Apply normalization factor
            if (i == 0)
                result[i] = coef_0 * sum;  // Special case for k=0
            else
                result[i] = coef_n * sum;  // For k > 0
        }

        return result;
    }
}

namespace decoding
{
    std::vector<byte_t> rle(const std::vector<byte_t>& data) noexcept(true)
    {
        size_t size = data.size();
        std::vector<byte_t> result;
        byte_t count;

        for (size_t i = 0; i < size; i += 2)
        {
            result.push_back(data[i]);

            for (size_t j = 1; j < data[i + 1]; ++j)
                result.push_back(data[i]);
        }

        return result;
    }

    std::vector<byte_t> dct(const std::vector<byte_t>& data) noexcept(true)
    {
        size_t size = data.size();
        std::vector<byte_t> result;

        return result;
    }
}

#endif // _COMPRESSION_IPP_
