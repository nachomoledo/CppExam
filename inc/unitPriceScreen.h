#ifndef UNIT_PRICE_SCREEN_H
#define UNIT_PRICE_SCREEN_H

#include "baseScreen.h"
#include <list>

class UnitPriceScreen : public BaseScreen
{
    public:
        virtual ~UnitPriceScreen();
        UnitPriceScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif