#ifndef EXPRESS_SALES_QUOTING_H
#define EXPRESS_SALES_QUOTING_H

#include "uiManager.h"
#include "userInputManager.h"
#include "SalesQuotation.h"

class ExpressSalesQuoting : public IUserInputObserver
{
    public:
        ExpressSalesQuoting(UserInputManager &userInputManager);
        void update(int userInput) override;
        void run(void);

    private:
        std::list<SalesQuotation> m_salesQuotationList;
        UIManager m_uiManager;
        UserInputManager &m_userInputManager;
        bool m_isRunning;
        bool m_exit;
        bool m_reload;
        std::shared_ptr<std::string> m_lastSalesQuotation;
};

#endif