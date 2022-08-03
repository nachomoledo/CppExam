#include "quantityScreen.h"
#include "utils.h"

QuantityScreen::~QuantityScreen()
{

}

QuantityScreen::QuantityScreen(std::string title)
    : BaseScreen(title)
{

}

std::string QuantityScreen::content()
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    str.append("\n");
//    str.append("INFORMACION: ");
//    str.append("EXISTE x CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
//    str.append("\n");
    str.append("PASO 5: Ingrese la cantidad de unidades a cotizar:");
    str.append(Utils::verticalSeparator());
    return str;
}