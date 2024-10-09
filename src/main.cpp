#include <iostream>
#include <cstring>

// Data compression functions
#include "../header/data_file.hpp"
#include "../header/compress.hpp"

/**
 * @brief Print a error message
 * @param msg Message
*/
void err_msg(const char[]) noexcept(true);

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

int main(int argc, char* argv[])
{
    if (argc == 1)
        err_msg("No arguments given");

    if (argc == 2 && !std::strcmp(argv[1], "--help"))
    {
        std::cout
            << "--list         Show all the possible algorithms\n"
            << "--comp         Compress the file\n"
            << "--decomp       Revert the compression process\n"
            << "Syntax: squeeze [process] [algorithm] [file 1] [file 2] ...\n";
        
        return 0;
    }

    if (argc == 2 && !std::strcmp(argv[1], "--list"))
    {
        std::cout
            << "--rle          Run-length encoding\n";

        return 0;
    }

    if (argc < 4)
        err_msg("Not enough arguments");

    process_t process_type = get_process_type(argv[1]);

    if (process_type == process_t::_invalid)
        err_msg("Process type is invalid");

    algorithm_t algorithm_type = get_algorithm_type(argv[2]);

    if (algorithm_type == algorithm_t::_none)
        err_msg("Algorithm choosen is not valid");

    std::string file_name;
    std::vector<byte_t>
        data_raw, // Raw data
        data_pro; // Processed data

    for (size_t i = 3; i < argc; ++i)
    {
        switch (algorithm_type)
        {
        case algorithm_t::_rle:
            
            file_name = argv[i];
            data_raw = load(file_name);

            if (process_type == process_t::_compress)
            {
                data_pro = compress::rle(data_raw);
                file_name += ".bin";
            }
            else
            {
                data_pro = decompress::rle(data_raw);
                file_name.resize(file_name.size() - 4);
            }

            save(data_pro, file_name);
            
            break;
        }

        file_name.clear();
        data_raw.clear();
        data_pro.clear();
    }

    std::cout << std::endl;

    return 0;
}

void err_msg(const char msg[]) noexcept(true)
{
    std::cout
        << "squeeze error: " << msg << '\n'
        << "For help try: squeeze --help\n";

    std::exit(1);
}

process_t get_process_type(const char arg[]) noexcept(true)
{
    if (!std::strcmp(arg, "--comp"))
        return process_t::_compress;
    if (!std::strcmp(arg, "--decomp"))
        return process_t::_decompress;

    return process_t::_invalid;
}

algorithm_t get_algorithm_type(const char arg[]) noexcept(true)
{
    if (!std::strcmp(arg, "--rle"))
        return algorithm_t::_rle;

    return algorithm_t::_none;
}
