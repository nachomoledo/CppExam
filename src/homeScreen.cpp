#include "homeScreen.h"
#include "utils.h"
#include <iostream>

HomeScreen::~HomeScreen()
{

}

HomeScreen::HomeScreen(std::string title,
                       std::string storeName,
                       std::string storeAddress,
                       std::string sellerName,
                       std::string sellerSurname,
                       std::string sellerId)
    : BaseScreen(title), m_storeName(storeName), 
      m_storeAddress(storeAddress), m_sellerName(sellerName),
      m_sellerSurname(sellerSurname), m_sellerId(sellerId)
{

}                      

std::string HomeScreen::content()
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(m_storeName);
    str.append(Utils::horizontalSeparator());
    str.append(m_storeAddress);
    str.append(Utils::verticalSeparator());
    str.append(m_sellerName);
    str.append(" ");
    str.append(m_sellerSurname);
    str.append(Utils::horizontalSeparator());
    str.append(m_sellerId);
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("SELECCIONE UNA OPIÓN DEL MENÚ:");
    str.append("\n");
    str.append("\n");
    str.append("1) Historial de Cotizaciones");
    str.append("\n");
    str.append("2) Realizar Cotización");
    str.append("\n");
    str.append("3) Salir");
    return str;
}