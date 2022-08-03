#ifndef EXPRESS_SALES_QUOTING_H
#define EXPRESS_SALES_QUOTING_H

#include "uiManager.h"
#include "userInputManager.h"
#include "salesQuotation.h"
#include "store.h"
#include "seller.h"

class ExpressSalesQuoting : public IUserInputObserver
{
    public:
        ExpressSalesQuoting(UserInputManager &userInputManager, Seller &seller, Store &store);
        void update(int userInput) override;
        void run(void);

    private:
        std::list<SalesQuotation> m_salesQuotationList;
        std::unique_ptr<UIManager> m_uiManager;
        UserInputManager &m_userInputManager;
        Seller &m_seller;
        Store &m_store;
        bool m_isRunning;
        bool m_exit;
        bool m_reload;
        bool m_printError;
        int m_stock;
        std::shared_ptr<std::string> m_lastSalesQuotation;
};

#endif