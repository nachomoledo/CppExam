#include "uiManager.h"
#include <amountScreen.h>
#include <finalPriceScreen.h>
#include <historyScreen.h>
#include <homeScreen.h>
#include <pantTypeScreen.h>
#include <qualityScreen.h>
#include <salesQuoteScreen.h>
#include <shirtCollarScreen.h>
#include <shirtSleeveScreen.h>
#include <singlePriceScreen.h>
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

UIManager::UIManager(UserInputManager &subject)
    : m_subject(subject)
{
    this->m_subject.attach(this);
    BaseScreen *screen = nullptr;
    std::string cotizarStr = std::string(APP_NAME) + "- COTIZAR";
    screen = new HomeScreen(std::string(APP_NAME) + " - MENU PRINCIPAL", STORE_NAME, STORE_ADDRESS, SELLER_NAME, SELLER_SURNAME, SELLER_ID);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::HOME, screen));
    screen->print();
    screen = new HistoryScreen(std::string(APP_NAME) + "- HISTORIAL DE COTIZACIONES");
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SALES_QUOTE_HISTORY, screen));
    screen = new SalesQuoteScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::NEW_SALES_QUOTE, screen));
    screen = new ShirtCollarScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SHIRT_COLLAR, screen));
    screen = new ShirtSleeveScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SHIRT_SLEEVE, screen));
    screen = new PantTypeScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::PANT_TYPE, screen));
    screen = new QualityScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::QUALITY, screen));
    screen = new SinglePriceScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::SINGLE_PRICE, screen));
    screen = new AmountScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::AMOUNT, screen));
    screen = new FinalPriceScreen(cotizarStr);
    m_screenMap.insert(std::pair<ScreenId, BaseScreen *>(ScreenId::FINAL_PRICE, screen));
}

UIManager::~UIManager()
{

}

void UIManager::update(int userInput)
{
    std::cout << __FUNCTION__ << "(userInput = " << userInput << ")" << std::endl;
    if (2 == userInput)
    {
        changeScreen(ScreenId::NEW_SALES_QUOTE);
    }
    m_lastInput = userInput;
}

void UIManager::changeScreen(ScreenId newScreen)
{
    if (m_screenMap.count(newScreen) > 0)
    {
        clearScreen();
        m_screenMap.at(newScreen)->print();
    }
}