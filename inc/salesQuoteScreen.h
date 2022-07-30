#ifndef SALES_QUOTE_SCREEN
#define SALES_QUOTE_SCREEN

#include "baseScreen.h"
#include <list>

class SalesQuoteScreen : public BaseScreen
{
    public:
        virtual ~SalesQuoteScreen();
        SalesQuoteScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif