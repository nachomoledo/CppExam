#include "pantTypeScreen.h"
#include "utils.h"

PantTypeScreen::~PantTypeScreen()
{

}

PantTypeScreen::PantTypeScreen(std::string title)
    : BaseScreen(title)
{

}

std::string PantTypeScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("PASO 2: El Pantalon a cotizar, es Chupin?");
    str.append("\n");
    str.append("1) Si");
    str.append("\n");
    str.append("2) No");
    str.append(Utils::verticalSeparator());
    return str;
}
}