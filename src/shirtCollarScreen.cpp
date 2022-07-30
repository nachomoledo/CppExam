#include "shirtCollarScreen.h"

ShirtCollarScreen::~ShirtCollarScreen()
{

}

ShirtCollarScreen::ShirtCollarScreen(std::string title)
    : BaseScreen(title)
{

}

std::string ShirtCollarScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());
    str.append("\n");
    str.append("PASO 2.b: La camisa a cotizar, ¿Es Cuello Mao?:");
    str.append("\n");
    str.append("1) Sí");
    str.append("\n");
    str.append("2) No");
    str.append(verticalSeparator());
    return str;
}
}