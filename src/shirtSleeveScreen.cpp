#include "shirtSleeveScreen.h"
#include "utils.h"

ShirtSleeveScreen::~ShirtSleeveScreen()
{

}

ShirtSleeveScreen::ShirtSleeveScreen(std::string title)
    : BaseScreen(title)
{

}

std::string ShirtSleeveScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("PASO 2.a: La camisa a cotizar, ¿Es Manga Corta?:");
    str.append("\n");
    str.append("1) Sí");
    str.append("\n");
    str.append("2) No");
    str.append(Utils::verticalSeparator());
    return str;
}
}