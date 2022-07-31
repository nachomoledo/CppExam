#include "salesQuotationScreen.h"
#include "utils.h"

SalesQuotationScreen::~SalesQuotationScreen()
{

}

SalesQuotationScreen::SalesQuotationScreen(std::string title)
    : BaseScreen(title)
{

}

std::string SalesQuotationScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("PASO 1: Seleccione la prenda a cotizar:");
    str.append("\n");
    str.append("1) Camisa");
    str.append("\n");
    str.append("2) Pantalón");
    str.append(Utils::verticalSeparator());
    return str;
}
}