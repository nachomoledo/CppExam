#include "historyScreen.h"
#include "utils.h"

HistoryScreen::~HistoryScreen()
{

}

HistoryScreen::HistoryScreen(std::string title, std::list<SalesQuotation> &listReference)
    : BaseScreen(title), m_listReference(listReference)
{

}

std::string HistoryScreen::content()
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    for (SalesQuotation sq : m_listReference)
    {
        str.append(sq.toString());
        str.append("\n");
        str.append(Utils::verticalSeparator());
    }
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    return str;
}