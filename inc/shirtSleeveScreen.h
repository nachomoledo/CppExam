#ifndef SHIRT_SLEEVE_SCREEN
#define SHIRT_SLEEVE_SCREEN

#include "baseScreen.h"
#include <list>

class ShirtSleeveScreen : public BaseScreen
{
    public:
        virtual ~ShirtSleeveScreen();
        ShirtSleeveScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif