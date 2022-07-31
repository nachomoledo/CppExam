#include "expressSalesQuoting.h"

ExpressSalesQuoting::ExpressSalesQuoting(UserInputManager &userInputManager)
    : m_userInputManager(userInputManager)
{
    this->m_userInputManager.attach(this);
    m_uiManager.changeScreen(ScreenId::HOME);
    m_userInputManager.getUserInput();
}

void ExpressSalesQuoting::update(int userInput)
{
    std::cout << __FUNCTION__ << "(userInput = " << userInput << ")" << std::endl;

    bool getNewInput = false;

    switch (m_uiManager.getCurrentScreen())
    {
    case ScreenId::HOME:
    {
        if (2 == userInput)
        {
            m_uiManager.changeScreen(ScreenId::NEW_SALES_QUOTE);
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
        break;
    }
}
