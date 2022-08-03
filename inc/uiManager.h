#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "baseScreen.h"
#include "salesQuotation.h"
#include "seller.h"
#include "store.h"
#include <map>
#include <memory>
#include <list>

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
        UIManager(Seller &seller, Store &store, std::shared_ptr<std::string> &salesQuotation, std::list<SalesQuotation> &listReference);
        virtual ~UIManager(void);
        void changeScreen(ScreenId newScreen);
        ScreenId getCurrentScreen(void);

    private:
        Seller &m_seller;
        Store &m_store;
        std::map<ScreenId, std::shared_ptr<BaseScreen>> m_screenMap;
        ScreenId m_currentScreen;
        void clearScreen(void);
};

#endif