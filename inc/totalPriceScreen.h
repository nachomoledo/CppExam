#ifndef TOTAL_PRICE_SCREEN_H
#define TOTAL_PRICE_SCREEN_H

#include "baseScreen.h"
#include <list>

class TotalPriceScreen : public BaseScreen
{
    public:
        virtual ~TotalPriceScreen();
        TotalPriceScreen(std::string title, std::string &salesQuotation);

    protected:
        std::string content(void) override;
        
    private:
        std::string &m_salesQuotation;
};

#endif