#include "userInputManager.h"
  
UserInputManager::~UserInputManager()
{

}

void UserInputManager::attach(IUserInputObserver *observer)
{
    m_observerList.push_back(observer);
}

void UserInputManager::detach(IUserInputObserver *observer) 
{
    m_observerList.remove(observer);
}

void UserInputManager::getUserInput() 
{
    std::cin >> m_lastInput;
    notify();
}

void UserInputManager::notify()
{
    std::list<IUserInputObserver *>::iterator iterator = m_observerList.begin();
    while (iterator != m_observerList.end()) {
        (*iterator)->update(m_lastInput);
        ++iterator;
    }
}
