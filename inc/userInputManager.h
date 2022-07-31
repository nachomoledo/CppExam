#ifndef USER_INPUT_MANAGER_H
#define USER_INPUT_MANAGER_H

#include "subject.h"
#include <list>
#include <iostream>

class UserInputManager : public ISubject
{
    public:
        UserInputManager();
        virtual ~UserInputManager();
        void attach(IUserInputObserver *observer) override;
        void detach(IUserInputObserver *observer) override;
        void getUserInput(void);

    private:
        std::list<IUserInputObserver *> m_observerList;
        int m_lastInput;
        void notify(void) override;
        bool m_awaitingInput;
};

#endif