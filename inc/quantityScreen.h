#ifndef QUANTITY_SCREEN_H
#define QUANTITY_SCREEN_H

#include "baseScreen.h"
#include <list>

class QuantityScreen : public BaseScreen
{
    public:
        virtual ~QuantityScreen();
        QuantityScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif