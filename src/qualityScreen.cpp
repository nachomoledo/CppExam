#include "qualityScreen.h"
#include "utils.h"

QualityScreen::~QualityScreen()
{

}

QualityScreen::QualityScreen(std::string title)
    : BaseScreen(title)
{

}

std::string QualityScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(Utils::verticalSeparator());
    str.append("\n");
    str.append("PASO 3: Seleccione la calidad de la prenda:");
    str.append("\n");
    str.append("1) Standard");
    str.append("\n");
    str.append("2) Premium");
    str.append(Utils::verticalSeparator());
    return str;
}
}