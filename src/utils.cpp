#include "utils.h"

#define WIDTH 80

std::string Utils::verticalSeparator(void)
{
    std::string str;
    str.append("\n");
    str.append(std::string(WIDTH, '-'));
    str.append("\n");
    return str;
}

std::string Utils::horizontalSeparator(void)
{
    return std::string(" | ");    
}
