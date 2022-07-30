#include "amountScreen.h"

AmountScreen::~AmountScreen()
{

}

AmountScreen::AmountScreen(std::string title)
    : BaseScreen(title)
{

}

std::string AmountScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());
    str.append("\n");
    str.append("INFORMACIÓN");
    str.append("EXISTE x CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
    str.append("\n");
    str.append("PASO 5: Ingrese la cantidad de unidades a cotizar:");
    str.append(verticalSeparator());
    return str;
}
}