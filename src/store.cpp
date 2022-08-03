#include "store.h"

Store::Store(std::string name, std::string address)
    : m_name(name), m_address(address)
{

}

std::string Store::getName()
{
    return m_name;
}

std::string Store::getAddress()
{
    return m_address;
}