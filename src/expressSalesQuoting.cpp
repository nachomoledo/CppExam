#include "expressSalesQuoting.h"
#include "defines.h"
#include "shirt.h"
#include "pant.h"

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

        while (false == m_exit)
        {

            if (false == m_exit)
            {
                m_userInputManager.getUserInput();
            }
            else
            {
                break;
            }

            if (true == m_reload)
            {
                m_uiManager.changeScreen(m_uiManager.getCurrentScreen());
            }


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
//    std::cout << __FUNCTION__ << "(userInput = " << userInput << ")" << std::endl;
    static std::unique_ptr<Garment> m_currentGarment;
    static std::unique_ptr<SalesQuotation> m_currentSalesQuotation;
    static int unitPrice = 0;
    static int quantity = 0;
    
    m_reload = false;

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
            m_reload = true;
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
            m_reload = true;
        }        
    }
    break;
    case ScreenId::NEW_SALES_QUOTE:
    {
        if (1 == userInput)
        {
            m_currentGarment = std::unique_ptr<Garment>(new Shirt());
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
            m_reload = true;
        }    
    }
    break;
    case ScreenId::SHIRT_SLEEVE:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            Shirt *shirt = dynamic_cast<Shirt*>(m_currentGarment.get());
            if (shirt)
            {
                shirt->setSleeveId((1 == userInput) ? ShirtSleeveId::Short : ShirtSleeveId::Long);
                m_uiManager.changeScreen(ScreenId::SHIRT_COLLAR);
            }
            else
            {
                std::cout << "Dynamic cast error" << std::endl;
                m_exit = true;
            }
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            m_reload = true;
        }   
    }
    break;
    case ScreenId::SHIRT_COLLAR:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            Shirt *shirt = dynamic_cast<Shirt*>(m_currentGarment.get());
            if (shirt)
            {
                shirt->setCollarId((1 == userInput) ? ShirtCollarId::Mao : ShirtCollarId::Classic);
                m_uiManager.changeScreen(ScreenId::QUALITY);
            }
            else
            {
                std::cout << "Dynamic cast error" << std::endl;
                m_exit = true;
            }
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            m_reload = true;
        }   
    }
    break;    
    case ScreenId::PANT_TYPE:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            Pant *pant = dynamic_cast<Pant*>(m_currentGarment.get());
            if (pant)
            {
            pant->setPantTypeId((1 == userInput) ? PantTypeId::SlimFit : PantTypeId::Classic);
            m_uiManager.changeScreen(ScreenId::QUALITY);
            }
            else
            {
                std::cout << "Dynamic cast error" << std::endl;
                m_exit = true;
            }
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            m_reload = true;
        }  
    }
    break;
    case ScreenId::QUALITY:
    {
        if ((1 == userInput) || (2 == userInput))
        {
            m_currentGarment->setQualityId((1 == userInput) ? QualityId::Standard : QualityId::Premium);
            m_uiManager.changeScreen(ScreenId::UNIT_PRICE);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            m_reload = true;
        } 
    }
    break;    
    case ScreenId::UNIT_PRICE:
    {
        //FIXME: back to home screen and positive/float values
        if (userInput > 0)
        {
            unitPrice = userInput;
            m_uiManager.changeScreen(ScreenId::QUANTITY);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }
        else
        {
            m_reload = true;
        }        
    }
    break;    
    case ScreenId::QUANTITY:
    {
        //FIXME: cantidad > stock
        //FIXME: back to home screen and positive values
        if (userInput > 0)
        {
            quantity = userInput;
            SalesQuotation sq = SalesQuotation("date", "time", 1, "detalles prenda", unitPrice, quantity, unitPrice*quantity);
            m_salesQuotationList.push_back(sq);
            m_uiManager.setLastSalesQuotation(sq.toString());
            m_uiManager.changeScreen(ScreenId::TOTAL_PRICE);
        }
        else if (BACK_VALUE == userInput)
        {
            m_uiManager.changeScreen(ScreenId::HOME);
        }        
        else
        {
            m_reload = true;
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
            m_reload = true;
        } 
    }
    break;
    default:
    {
        m_reload = true;
    }
        break;
    }
}
