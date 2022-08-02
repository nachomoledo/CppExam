#include "shirtCollarScreen.h"
#include "utils.h"

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
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("PASO 2.b: La camisa a cotizar, es Cuello Mao?:");
    str.append("\n");
    str.append("1) Si");
    str.append("\n");
    str.append("2) No");
    str.append(Utils::verticalSeparator());
    return str;
}
}