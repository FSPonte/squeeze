#include <iostream>

// Dependencies
#include "../header/utils.hpp"
#include "../header/file_handler.hpp"
#include "../header/compression.hpp"

const func_ptr function_matrix[2][algorithm_t::size] =
{
    {&encoding::rle, &encoding::dct},
    {&decoding::rle, &decoding::dct}
};

int main(int argc, char* argv[])
{
    if (argc == 1)
        err_msg("No arguments given");

    if (argc == 2 && !std::strcmp(argv[1], "--help"))
    {
        std::cout
            << "Processes:\n"
            << "\t--comp         Compress the file\n"
            << "\t--decomp       Revert the compression process\n\n"
            << "Algorithms:\n"
            << "\t--rle          Run-length encoding\n"
            << "\t--dct          Discrete cosine transform\n\n"
            << "Syntax: squeeze [process] [algorithm] [file name] ...\n";
        
        return 0;
    }

    if (argc < 4)
        err_msg("Not enough arguments");

    process_t process_type;
    algorithm_t algorithm_type;
    std::string file_name;
    std::vector<byte_t>
        data_raw, // Raw data
        data_pro; // Processed data

    for (size_t i = 1; i < argc; i += 3)
    {
        process_type = get_process_type(argv[i]);

        if (process_type == process_t::_invalid)
            continue;
        
        algorithm_type = get_algorithm_type(argv[i + 1]);

        if (algorithm_type == algorithm_t::_none)
            continue;

        file_name = argv[i + 2];

        try
        {
            data_raw = load(file_name);

            if (process_type == process_t::_encode)
                file_name += ".bin";
            else
                file_name.resize(file_name.size() - 4);

            data_pro = function_matrix[process_type][algorithm_type](data_raw);
            save(data_pro, file_name);
            std::cout << "squeeze: " << argv[i + 2] << " > " << file_name << '\n';
        }
        catch (const char exception_message[])
        {
            exc_msg(exception_message);
            continue;
        }

        file_name.clear();
        data_raw.clear();
        data_pro.clear();
    }

    std::cout << std::flush;

    return 0;
}
