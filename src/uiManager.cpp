#include "uiManager.h"

UIManager::UIManager(UserInputManager &subject)
    : m_subject(subject)
{
    this->m_subject.attach(this);
}

UIManager::~UIManager()
{

}

void UIManager::update(int userInput)
{
    std::cout << __FUNCTION__ << "(userInput = " << userInput << ")" << std::endl;
    m_lastInput = userInput;
}