#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "baseScreen.h"
#include <map>
#include <memory>

enum class ScreenId
{
    HOME,
    SALES_QUOTE_HISTORY,
    NEW_SALES_QUOTE,
    SHIRT_SLEEVE,
    SHIRT_COLLAR,
    PANT_TYPE,
    QUALITY,
    UNIT_PRICE,
    QUANTITY,
    TOTAL_PRICE
};

class UIManager
{
    public:
        UIManager();
        virtual ~UIManager(void);
        void changeScreen(ScreenId newScreen);
        void setLastSalesQuotation(std::string lastSalesQuotation);
        ScreenId getCurrentScreen(void);

    private:
        std::map<ScreenId, std::unique_ptr<BaseScreen>> m_screenMap;
        std::string m_lastSalesQuotation;
        ScreenId m_currentScreen;
        void clearScreen(void);
};

#endif