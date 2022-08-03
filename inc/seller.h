#ifndef SELLER_H
#define SELLER_H

#include <string>

class Seller
{
    public:
        Seller(std::string name, std::string surname);
        std::string getName();
        std::string getSurname();
        int getCode();

    private:
        static int m_nextCode;
        int m_code;
        std::string m_name;
        std::string m_surname;
};

#endif