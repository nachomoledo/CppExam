#ifndef HISTORY_SCREEN_H
#define HISTORY_SCREEN_H

#include "baseScreen.h"
#include <list>
#include <memory>
#include "SalesQuotation.h"

class HistoryScreen : public BaseScreen
{
    public:
        virtual ~HistoryScreen();
        HistoryScreen(std::string title, std::list<SalesQuotation> &listReference);

    protected:
        std::string content(void) override;
    
    private:
        std::list<SalesQuotation> &m_listReference;
};

#endif