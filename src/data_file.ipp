#ifndef _DATA_FILE_IPP_
#define _DATA_FILE_IPP_

std::vector<byte_t> load(const char file_name[]) noexcept(false)
{
    if (file_name == nullptr)
        throw "Invalid file name";

    std::ifstream file(file_name, std::ios::binary);

    if (!file.is_open())
        throw "File did not open";

    if (!file.good())
        throw "File is not good";

    std::vector<byte_t> data;
    byte_t byte;

    while (file.read(&byte, sizeof(byte_t)))
        data.push_back(byte);

    file.close();

    return data;
}

void save(const std::vector<byte_t>& data, const char file_name[]) noexcept(false)
{
    if (file_name == nullptr)
        throw "Invalid file name";

    std::ofstream file(file_name, std::ios::binary);

    if (!file.is_open())
        throw "File did not open";

    if (!file.good())
        throw "File is not good";

    const size_t size = data.size();

    for (size_t i = 0; i < size; ++i)
        file << data[i];

    file.close();
}

#endif // _DATA_FILE_IPP_
