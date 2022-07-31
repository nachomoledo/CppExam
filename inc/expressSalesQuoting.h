#ifndef EXPRESS_SALES_QUOTING_H
#define EXPRESS_SALES_QUOTING_H

#include "uiManager.h"
#include "userInputManager.h"

class ExpressSalesQuoting : public IUserInputObserver
{
    public:
        ExpressSalesQuoting(UserInputManager &userInputManager);
        void update(int userInput) override;

    private:
        UIManager m_uiManager;
        UserInputManager &m_userInputManager;
};

#endif