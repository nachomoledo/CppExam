#ifndef HISTORY_SCREEN
#define HISTORY_SCREEN

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