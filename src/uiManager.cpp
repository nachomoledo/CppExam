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
    BaseScreen *screen = nullptr;
    std::string cotizarStr = std::string(APP_NAME) + "- COTIZAR";
    screen = new HomeScreen(std::string(APP_NAME) + " - MENU PRINCIPAL", STORE_NAME, STORE_ADDRESS, SELLER_NAME, SELLER_SURNAME, SELLER_ID);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::HOME, screen));
    screen->print();
    screen = new HistoryScreen(std::string(APP_NAME) + "- HISTORIAL DE COTIZACIONES");
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SALES_QUOTE_HISTORY, screen));
    screen = new SalesQuotationScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::NEW_SALES_QUOTE, screen));
    screen = new ShirtCollarScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SHIRT_COLLAR, screen));
    screen = new ShirtSleeveScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SHIRT_SLEEVE, screen));
    screen = new PantTypeScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::PANT_TYPE, screen));
    screen = new QualityScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::QUALITY, screen));
    screen = new UnitPriceScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::UNIT_PRICE, screen));
    screen = new QuantityScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::QUANTITY, screen));
    screen = new TotalPriceScreen(cotizarStr, m_lastSalesQuotation);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::TOTAL_PRICE, screen));
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
    m_currentScreen;
}