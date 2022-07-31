#include "seller.h"

int Seller::m_nextCode = 0;

Seller::Seller(std::string name, std::string surname)
    : m_code(++m_nextCode), m_name(name), m_surname(surname)
{

}