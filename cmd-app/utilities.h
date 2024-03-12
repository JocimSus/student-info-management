#include <string>

std::string lowerString(std::string string)
{
    std::string lowercase_string = 0;
    for (auto c : string)
    {
        lowercase_string.push_back(tolower(c));
    }
    return lowercase_string;
}