#include "singlePriceScreen.h"

SinglePriceScreen::~SinglePriceScreen()
{

}

SinglePriceScreen::SinglePriceScreen(std::string title)
    : BaseScreen(title)
{

}

std::string SinglePriceScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());
    str.append("\n");
    str.append("PASO 4: Ingrese el precio unitario de la prenda a cotizar:");
    str.append(verticalSeparator());
    return str;
}
}