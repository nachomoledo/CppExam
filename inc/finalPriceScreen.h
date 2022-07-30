#ifndef FINAL_PRICE_SCREEN
#define FINAL_PRICE_SCREEN

#include "baseScreen.h"
#include <list>

class FinalPriceScreen : public BaseScreen
{
    public:
        virtual ~FinalPriceScreen();
        FinalPriceScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif