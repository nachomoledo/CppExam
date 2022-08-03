#include "expressSalesQuoting.h"
#include "defines.h"
#include "shirt.h"
#include "pant.h"

ExpressSalesQuoting::ExpressSalesQuoting(UserInputManager &userInputManager)
    : m_userInputManager(userInputManager), m_isRunning(false), m_exit(false)
{
    m_lastSalesQuotation = std::make_shared<std::string>("");
    m_uiManager = UIManager(m_lastSalesQuotation, m_salesQuotationList);
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
            /*static int i = 0;
            std::cout << "while " << i << std::endl;
            i++;
            
            if (i > 100) break;*/


        }
    }


}

std::string ExpressSalesQuoting::getDateString(time_t t)
{
    tm *ltm = localtime(&t);
    return    std::string(std::to_string( 1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday));
}

std::string ExpressSalesQuoting::getTimeString(time_t t)
{
    tm *ltm = localtime(&t);
    return    std::string(std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec));
}


void ExpressSalesQuoting::update(int userInput)
{
//    std::cout << __FUNCTION__ << "(userInput = " << userInput << ")" << std::endl;
    static std::shared_ptr<Garment> m_currentGarment;
    static std::shared_ptr<SalesQuotation> m_currentSalesQuotation;
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
            m_currentGarment = std::shared_ptr<Garment>(new Shirt());
            m_uiManager.changeScreen(ScreenId::SHIRT_SLEEVE);
        }
        else if (2 == userInput)
        {
            m_currentGarment = std::shared_ptr<Garment>(new Pant());
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
                std::cout << "Dynamic cast error (shirt sleeve)" << std::endl;
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
                std::cout << "Dynamic cast error (shirt collar)" << std::endl;
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
            pant->setPantTypeId((1 == userInput) ? PantTypeId::SlimFit : PantTypeId::Standard);
            m_uiManager.changeScreen(ScreenId::QUALITY);
            }
            else
            {
                std::cout << "Dynamic cast error (pant)" << std::endl;
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
            m_currentGarment->setQualityId((1 == userInput) ? GarmentQualityId::Standard : GarmentQualityId::Premium);
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
            time_t now = time(0);
            SalesQuotation sq = SalesQuotation(getDateString(now), getTimeString(now), 1, m_currentGarment->toString(), unitPrice, quantity, unitPrice*quantity);
            m_salesQuotationList.push_back(sq);
           *m_lastSalesQuotation = sq.toString();
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
