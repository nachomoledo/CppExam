#ifndef QUALITY_SCREEN
#define QUALITY_SCREEN

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