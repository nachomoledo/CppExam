#ifndef SHIRT_COLLAR_SCREEN
#define SHIRT_COLLAR_SCREEN

#include "baseScreen.h"
#include <list>

class ShirtCollarScreen : public BaseScreen
{
    public:
        virtual ~ShirtCollarScreen();
        ShirtCollarScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif