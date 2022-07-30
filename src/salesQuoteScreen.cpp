#include "salesQuoteScreen.h"

SalesQuoteScreen::~SalesQuoteScreen()
{

}

SalesQuoteScreen::SalesQuoteScreen(std::string title)
    : BaseScreen(title)
{

}

std::string SalesQuoteScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());
    str.append("\n");
    str.append("PASO 1: Seleccione la prenda a cotizar:");
    str.append("\n");
    str.append("1) Camisa");
    str.append("\n");
    str.append("2) Pantalón");
    str.append(verticalSeparator());
    return str;
}
}