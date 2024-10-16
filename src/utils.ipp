#ifndef _UTILS_IPP_
#define _UTILS_IPP_

void err_msg(const char msg[]) noexcept(false)
{
    if (msg == nullptr)
        throw "Error message is a null pointer";
    
    std::cout
        << "squeeze error: " << msg << '\n'
        << "For help try: squeeze --help\n";

    std::exit(1);
}

void exc_msg(const char msg[]) noexcept(false)
{
    if (msg == nullptr)
        throw "Exception message is a null pointer";

    std::cout << "squeeze exception: " << msg << '\n';
}

process_t get_process_type(const char arg[]) noexcept(false)
{
    if (arg == nullptr)
        throw "Process type string is a null pointer";

    if (!std::strcmp(arg, "--comp"))
        return process_t::_encode;
    if (!std::strcmp(arg, "--decomp"))
        return process_t::_decode;

    return process_t::_invalid;
}

algorithm_t get_algorithm_type(const char arg[]) noexcept(false)
{
    if (arg == nullptr)
        throw "Algorithm type string is a null pointer";

    if (!std::strcmp(arg, "--rle"))
        return algorithm_t::_rle;
    if (!std::strcmp(arg, "--dct"))
        return algorithm_t::_dct;

    return algorithm_t::_none;
}

#endif // _UTILS_IPP_
