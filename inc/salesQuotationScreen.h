#ifndef SALES_QUOTATION_SCREEN_H
#define SALES_QUOTATION_SCREEN_H

#include "baseScreen.h"
#include <list>

class SalesQuotationScreen : public BaseScreen
{
    public:
        virtual ~SalesQuotationScreen();
        SalesQuotationScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif