#ifndef TOTAL_PRICE_SCREEN_H
#define TOTAL_PRICE_SCREEN_H

#include "baseScreen.h"
#include <memory>

class TotalPriceScreen : public BaseScreen
{
    public:
        virtual ~TotalPriceScreen();
        TotalPriceScreen(std::string title, std::shared_ptr<std::string> &salesQuotation);

    protected:
        std::string content(void) override;
        
    private:
        std::shared_ptr<std::string> m_salesQuotation;
};

#endif