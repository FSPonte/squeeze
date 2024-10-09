#ifndef _COMPRESS_IPP_
#define _COMPRESS_IPP_

std::vector<byte_t> rle(const std::vector<byte_t>& data) noexcept(true)
{
    std::vector<byte_t> ret;
    size_t
        size = data.size(),
        count;

    for (size_t i = 0; i < size; ++i)
    {
        count = 1;

        while (i < size - 1 && data[i] == data[i + 1]) 
        {
            ++count;
            ++i;
        }

        ret.push_back(data[i]);
        ret.push_back(count);
    }

    return ret;
}

#endif // _COMPRESS_IPP_
