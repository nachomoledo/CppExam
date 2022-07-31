#include "historyScreen.h"
#include "utils.h"

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
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    return str;
}
}