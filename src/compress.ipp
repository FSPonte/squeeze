#ifndef _COMPRESS_IPP_
#define _COMPRESS_IPP_

std::vector<std::pair<byte_t, size_t>> rle(const std::vector<byte_t>& input) noexcept(true)
{
    std::vector<std::pair<byte_t, size_t>> encoded;
    size_t
        size = input.size(),
        count;

    for (size_t i = 0; i < size; ++i)
    {
        count = 1;

        while (i < size - 1 && input[i] == input[i + 1]) 
        {
            ++count;
            ++i;
        }

        encoded.push_back(std::make_pair(input[i], count));
    }

    return encoded;
}

#endif // _COMPRESS_IPP_
