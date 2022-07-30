#ifndef UI_MANAGER
#define UI_MANAGER

#include "baseScreen.h"
#include "userInputManager.h"

#include <map>

enum class ScreenId
{
    HOME,
    SALES_QUOTE_HISTORY,
    NEW_SALES_QUOTE,
    SHIRT_COLLAR,
    SHIRT_SLEEVE,
    PANT_TYPE,
    QUALITY,
    SINGLE_PRICE,
    AMOUNT,
    FINAL_PRICE
};

class UIManager : public IUserInputObserver
{
    public:
        UIManager(UserInputManager &subject);
        virtual ~UIManager(void);
        void update(int userInput) override;
        void changeScreen(ScreenId newScreen);

    private:
        std::map<ScreenId, BaseScreen *> m_screenMap;
        int m_lastInput;
        UserInputManager &m_subject;
        void clearScreen(void);
};

#endif