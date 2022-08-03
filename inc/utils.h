#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils 
{
    public:
        static std::string verticalSeparator(void);
        static std::string horizontalSeparator(void);
        static std::string backMessage(void);
        static std::string floatToString(float f, uint8_t precision);
};



#endif