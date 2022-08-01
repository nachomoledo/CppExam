#include "uiManager.h"
#include <quantityScreen.h>
#include <totalPriceScreen.h>
#include <historyScreen.h>
#include <homeScreen.h>
#include <pantTypeScreen.h>
#include <qualityScreen.h>
#include <salesQuotationScreen.h>
#include <shirtCollarScreen.h>
#include <shirtSleeveScreen.h>
#include <unitPriceScreen.h>
#include "defines.h"
#include <cstdlib>

void UIManager::clearScreen()
{
#ifdef __MINGW32__
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

UIManager::UIManager()
{
    std::string cotizarStr = std::string(APP_NAME) + "- COTIZAR";
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::HOME,
        std::unique_ptr<BaseScreen>(new HomeScreen(std::string(APP_NAME) + " - MENU PRINCIPAL", STORE_NAME, STORE_ADDRESS, SELLER_NAME, SELLER_SURNAME, SELLER_ID))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::SALES_QUOTE_HISTORY, 
        std::unique_ptr<BaseScreen>(new HistoryScreen(std::string(APP_NAME) + "- HISTORIAL DE COTIZACIONES"))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::NEW_SALES_QUOTE, 
        std::unique_ptr<BaseScreen>(new SalesQuotationScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::SHIRT_COLLAR, 
        std::unique_ptr<BaseScreen>(new ShirtCollarScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::SHIRT_SLEEVE, 
        std::unique_ptr<BaseScreen>(new ShirtSleeveScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::PANT_TYPE, 
        std::unique_ptr<BaseScreen>(new PantTypeScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::QUALITY, 
        std::unique_ptr<BaseScreen>(new QualityScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::UNIT_PRICE, 
        std::unique_ptr<BaseScreen>(new UnitPriceScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::QUANTITY, 
        std::unique_ptr<BaseScreen>(new QuantityScreen(cotizarStr))));
    m_screenMap.insert(std::make_pair<ScreenId, std::unique_ptr<BaseScreen>>(ScreenId::TOTAL_PRICE, 
        std::unique_ptr<BaseScreen>(new TotalPriceScreen(cotizarStr, m_lastSalesQuotation))));
}

UIManager::~UIManager()
{

}

void UIManager::changeScreen(ScreenId newScreen)
{
    if (m_screenMap.count(newScreen) > 0)
    {
        clearScreen();
        m_screenMap.at(newScreen)->print();
        m_currentScreen = newScreen;
    }
}

ScreenId UIManager::getCurrentScreen()
{
    return m_currentScreen;
}

void UIManager::setLastSalesQuotation(std::string lastSalesQuotation)
{
    m_lastSalesQuotation = lastSalesQuotation;
}
