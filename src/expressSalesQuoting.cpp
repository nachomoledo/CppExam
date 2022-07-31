#include "expressSalesQuoting.h"
#include "defines.h"

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
        else if (EXIT_VALUE == userInput)
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
        if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        }        
    }
    break;
    case ScreenId::NEW_SALES_QUOTE:
    {
        if (1 == userInput)
        {
            m_uiManager.changeScreen(ScreenId::SHIRT_SLEEVE);
        }
        else if (2 == userInput)
        {
            m_uiManager.changeScreen(ScreenId::PANT_TYPE);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        }    
    }
    break;
    case ScreenId::SHIRT_SLEEVE:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            m_uiManager.changeScreen(ScreenId::SHIRT_COLLAR);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        }   
    }
    break;
    case ScreenId::SHIRT_COLLAR:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            m_uiManager.changeScreen(ScreenId::QUALITY);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        }   
    }
    break;    
    case ScreenId::PANT_TYPE:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            m_uiManager.changeScreen(ScreenId::QUALITY);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        }  
    }
    break;
    case ScreenId::QUALITY:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            m_uiManager.changeScreen(ScreenId::UNIT_PRICE);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        } 
    }
    break;    
    case ScreenId::UNIT_PRICE:
    {
        //FIXME: back to home screen
        if (userInput > 0)
        {
            m_uiManager.changeScreen(ScreenId::QUANTITY);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        }        
    }
    break;    
    case ScreenId::QUANTITY:
    {
        //FIXME: cantidad > stock
        //FIXME: back to home screen
        if (userInput > 0)
        {
            m_uiManager.changeScreen(ScreenId::TOTAL_PRICE);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }        
        else
        {
            reload = true;
        }  
    }
    break;    
    case ScreenId::TOTAL_PRICE:
    {
        if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            reload = true;
        } 
    }
    break;
    default:
    {
        reload = true;
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
