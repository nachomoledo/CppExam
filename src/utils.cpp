#include "utils.h"
#include "defines.h"

#define WIDTH 80

std::string Utils::verticalSeparator()
{
    std::string str;
    str.append("\n");
    str.append(std::string(WIDTH, '-'));
    str.append("\n");
    return str;
}

std::string Utils::horizontalSeparator()
{
    return std::string(" | ");    
}

std::string Utils::backMessage()
{
    return std::string("Presiona " + std::to_string(BACK_VALUE) + " para volver al menú principal");    
}