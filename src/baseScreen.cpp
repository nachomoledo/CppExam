#include "baseScreen.h"
#include <iostream>

BaseScreen::BaseScreen(std::string title)
    : m_title(title) 
{

}

BaseScreen::~BaseScreen()
{

}

void BaseScreen::print(void)
{
    std::cout << content() << std::endl;
}