#include "baseScreen.h"
#include <iostream>

BaseScreen::BaseScreen(std::string title)
    : m_title(title) 
{

}

BaseScreen::~BaseScreen()
{

}


std::string BaseScreen::verticalSeparator(void)
{
    std::string str;
    str.append("\n");
    str.append(std::string(WIDTH, '-'));
    str.append("\n");
    return str;
}

std::string BaseScreen::horizontalSeparator(void)
{
    return std::string(" | ");    
}

void BaseScreen::print(void)
{
    std::cout << content() << std::endl;
}