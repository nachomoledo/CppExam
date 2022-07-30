#include "homeScreen.h"
#include <iostream>

HomeScreen::HomeScreen() 
    : BaseScreen()
{
    
}

HomeScreen::~HomeScreen()
{

}

HomeScreen::HomeScreen(std::string title,
                       std::string storeName,
                       std::string storeAddress,
                       std::string sellerName,
                       std::string sellerSurname,
                       std::string sellerId,
                       std::list<std::string> optionList)
    : BaseScreen(title), m_storeName(storeName), 
      m_storeAddress(storeAddress), m_sellerName(sellerName),
      m_sellerSurname(sellerSurname), m_sellerId(sellerId),
      m_optionList(optionList)
{

}                      

std::string HomeScreen::content()
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append(m_storeName);
    str.append(horizontalSeparator());
    str.append(m_storeAddress);
    str.append(verticalSeparator());
    str.append(m_sellerName);
    str.append(" ");
    str.append(m_sellerSurname);
    str.append(horizontalSeparator());
    str.append(m_sellerId);
    str.append(verticalSeparator());
    str.append("\n");
    str.append("SELECCIONE UNA OPIÓN DEL MENÚ:");
    str.append("\n");
    str.append("\n");

    for (std::string s : m_optionList)
    {
        str.append(s + "\n");
    }

    return str;
}

void HomeScreen::addOption(int number, std::string option)
{
    m_optionList.push_back(std::to_string(number) + ") " + option);
}

