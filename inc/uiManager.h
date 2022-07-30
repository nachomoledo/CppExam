#include "userInputManager.h"

class UIManager : public IUserInputObserver
{
    public:
        UIManager(UserInputManager &subject);
        virtual ~UIManager(void);
        void update(int userInput) override;

    private:
        int m_lastInput;
        UserInputManager &m_subject;
};