#ifndef HISTORY_SCREEN_H
#define HISTORY_SCREEN_H

#include "baseScreen.h"
#include <list>

class HistoryScreen : public BaseScreen
{
    public:
        virtual ~HistoryScreen();
        HistoryScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif