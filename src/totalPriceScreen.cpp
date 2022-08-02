#include "totalPriceScreen.h"
#include "utils.h"

TotalPriceScreen::~TotalPriceScreen()
{

}

TotalPriceScreen::TotalPriceScreen(std::string title, std::shared_ptr<std::string> &salesQuotation)
    : BaseScreen(title), m_salesQuotation(salesQuotation)
{

}

std::string TotalPriceScreen::content()
{
    std::string str;
    str.append(m_title);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());
    str.append(*m_salesQuotation);
    str.append(Utils::verticalSeparator());
    str.append(Utils::backMessage());
    str.append(Utils::verticalSeparator());

    return str;
}