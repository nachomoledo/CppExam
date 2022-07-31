#include "expressSalesQuoting.h"

ExpressSalesQuoting::ExpressSalesQuoting(UserInputManager &userInputManager)
    : m_userInputManager(userInputManager), m_isRunning(false), m_exit(false)
{
    
}

void ExpressSalesQuoting::run()
{
    if (false == m_isRunning)
    {
        this->m_userInputManager.attach(this);
        m_uiManager.changeScreen(ScreenId::HOME);
        m_isRunning = true;
        m_userInputManager.getUserInput();

        while (false == m_exit)
        {
            /* FIXME: eliminar variable de seguridad */
            static int i = 0;
            std::cout << "while " << i << std::endl;
            i++;
            if (i > 100) break;
        }
    }


}

void ExpressSalesQuoting::update(int userInput)
{
    std::cout << __FUNCTION__ << "(userInput = " << userInput << ")" << std::endl;

    bool reload = false;

    switch (m_uiManager.getCurrentScreen())
    {
    case ScreenId::HOME:
    {
        if (1 == userInput)
        {
            m_uiManager.changeScreen(ScreenId::SALES_QUOTE_HISTORY);
        }
        else if (2 == userInput)
        {
            m_uiManager.changeScreen(ScreenId::NEW_SALES_QUOTE);
        }
        else if (3 == userInput)
        {
            m_exit = true;
        }
        else
        {
            reload = true;
        }
    }
    break;
    case ScreenId::SALES_QUOTE_HISTORY:
    {
        
    }
    break;
    case ScreenId::NEW_SALES_QUOTE:
    {

    }
    break;
    case ScreenId::SHIRT_COLLAR:
    {

    }
    break;
    case ScreenId::SHIRT_SLEEVE:
    {

    }
    break;
    case ScreenId::PANT_TYPE:
    {

    }
    break;
    case ScreenId::QUALITY:
    {

    }
    break;
    case ScreenId::UNIT_PRICE:
    {

    }
    break;
    case ScreenId::QUANTITY:
    {

    }
    break;
    case ScreenId::TOTAL_PRICE:
    {

    }
    break;
    default:
    {

    }
        break;
    }

    if (true == reload)
    {
        m_uiManager.changeScreen(m_uiManager.getCurrentScreen());
    }

    if (false == m_exit)
    {
        m_userInputManager.getUserInput();
    }
}
