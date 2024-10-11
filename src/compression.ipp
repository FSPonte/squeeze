#ifndef _COMPRESSION_IPP_
#define _COMPRESSION_IPP_

namespace encoding
{
    std::vector<byte_t> rle(const std::vector<byte_t>& data) noexcept(true)
    {
        std::vector<byte_t> ret;
        size_t size = data.size();
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
                    ret.push_back(data[i]);
                    ret.push_back(count);
                    count = 1;
                }
            }

            ret.push_back(data[i]);
            ret.push_back(count);
        }

        return ret;
    }
}

namespace decoding
{
    std::vector<byte_t> rle(const std::vector<byte_t>& data) noexcept(true)
    {
        std::vector<byte_t> ret;
        size_t size = data.size();
        byte_t count;

        for (size_t i = 0; i < size; i += 2)
        {
            ret.push_back(data[i]);

            for (size_t j = 1; j < data[i + 1]; ++j)
                ret.push_back(data[i]);
        }

        return ret;
    }
}

#endif // _COMPRESSION_IPP_
