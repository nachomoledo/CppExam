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
//         HistoryScreen(std::string title, std::shared_ptr<std::list<SalesQuotation>> &listPtr);

    protected:
        std::string content(void) override;
    
    private:
//        std::shared_ptr<std::list<SalesQuotation>> m_listPtr;
        std::list<SalesQuotation> &m_listReference;
};

#endif