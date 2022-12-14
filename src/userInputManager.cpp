#include "userInputManager.h"  
#include <ios>
#include <limits>

UserInputManager::UserInputManager()
    : m_lastInput(0), m_awaitingInput(false)
{

}


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
    if(false == m_awaitingInput)
    {
        m_awaitingInput = true;
        std::cin >> m_lastInput;
        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese solo numeros" << std::endl;
            std::cin >> m_lastInput;
        }
        m_awaitingInput = false;
        notify();
    }

}

void UserInputManager::notify()
{
    std::list<IUserInputObserver *>::iterator iterator = m_observerList.begin();
    while (iterator != m_observerList.end()) {
        (*iterator)->update(m_lastInput);
        ++iterator;
    }
}
