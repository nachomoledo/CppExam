#ifndef BASE_SCREEN_H
#define BASE_SCREEN_H

#include "utils.h"
#include <string>

class BaseScreen
{
    public:
        BaseScreen(std::string title = "");
        virtual ~BaseScreen();
        void print(void);
    protected:
        std::string m_title;
        virtual std::string content(void) = 0;
};

#endif