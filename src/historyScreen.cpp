#include "historyScreen.h"

HistoryScreen::~HistoryScreen()
{

}

HistoryScreen::HistoryScreen(std::string title)
    : BaseScreen(title)
{

}

std::string HistoryScreen::content()
{
{
    std::string str;
    str.append(m_title);
    str.append(verticalSeparator());
    str.append("Presiona 3 para volver al menú principal");
    str.append(verticalSeparator());
    return str;
}
}