#include "finalPriceScreen.h"

FinalPriceScreen::~FinalPriceScreen()
{

}

FinalPriceScreen::FinalPriceScreen(std::string title)
    : BaseScreen(title)
{

}

std::string FinalPriceScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());
    str.append("Número de identificación: 001");
    str.append("\n");
    str.append("Fecha y Hora de la cotización: 18/01/2022 15:30");
    str.append("\n");
    str.append("Código del vendedor: 001");
    str.append("\n");
    str.append("Prenda cotizada: Camisa - Manga corta - Premium");
    str.append("\n");
    str.append("Precio unitario: $xx,xx");
    str.append("\n");    
    str.append("Cantidad de unidades cotizadas: 17");
    str.append("\n");
    str.append("Precio Final: $xx,xx");
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());    return str;
}
}