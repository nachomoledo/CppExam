#include "unitPriceScreen.h"
#include "utils.h"

UnitPriceScreen::~UnitPriceScreen()
{

}

UnitPriceScreen::UnitPriceScreen(std::string title)
    : BaseScreen(title)
{

}

std::string UnitPriceScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("PASO 4: Ingrese el precio unitario de la prenda a cotizar:");
    str.append(Utils::verticalSeparator());
    return str;
}
}