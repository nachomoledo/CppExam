#ifndef QUALITY_SCREEN_H
#define QUALITY_SCREEN_H

#include "baseScreen.h"
#include <list>

class QualityScreen : public BaseScreen
{
    public:
        virtual ~QualityScreen();
        QualityScreen(std::string title);

    protected:
        std::string content(void) override;
};

#endif