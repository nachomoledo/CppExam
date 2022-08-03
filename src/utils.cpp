#include "utils.h"
#include "defines.h"
#include <iomanip>
#include <sstream>

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
    return std::string("Presiona " + std::to_string(BACK_VALUE) + " para volver al menu principal");    
}


std::string Utils::floatToString(float f, uint8_t precision)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << f;
    return stream.str();
}

std::string Utils::getDateString(time_t t)
{
    return "--";
//    tm *ltm = localtime(&t);
//    return    std::string(std::to_string( 1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday));
}

std::string Utils::getTimeString(time_t t)
{
    return "--";
//    tm *ltm = localtime(&t);
//    return    std::string(std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec));
}
