#ifndef AMOUNT_SCREEN
#define AMOUNT_SCREEN

#include "baseScreen.h"
#include <list>

class AmountScreen : public BaseScreen
{
    public:
        virtual ~AmountScreen();
        AmountScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif