#ifndef SINGLE_PRICE_SCREEN
#define SINGLE_PRICE_SCREEN

#include "baseScreen.h"
#include <list>

class SinglePriceScreen : public BaseScreen
{
    public:
        virtual ~SinglePriceScreen();
        SinglePriceScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif