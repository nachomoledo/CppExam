#include "seller.h"

int Seller::m_nextCode = 0;

Seller::Seller(std::string name, std::string surname)
    : m_code(++m_nextCode), m_name(name), m_surname(surname)
{

}

std::string Seller::getName()
{
    return m_name;
}

std::string Seller::getSurname()
{
    return m_surname;
}

int Seller::getCode()
{
    return m_code;
}