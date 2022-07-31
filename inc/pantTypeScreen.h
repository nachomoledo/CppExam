#ifndef PANT_TYPE_SCREEN_H
#define PANT_TYPE_SCREEN_H

#include "baseScreen.h"
#include <list>

class PantTypeScreen : public BaseScreen
{
    public:
        virtual ~PantTypeScreen();
        PantTypeScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif