#ifndef USER_INPUT_MANAGER
#define USER_INPUT_MANAGER

#include "subject.h"
#include <list>
#include <iostream>

class UserInputManager : public ISubject
{
    public:
        virtual ~UserInputManager();
        void attach(IUserInputObserver *observer) override;
        void detach(IUserInputObserver *observer) override;
        void getUserInput(void);

    private:
        std::list<IUserInputObserver *> m_observerList;
        int m_lastInput;
        void notify(void) override;
};

#endif