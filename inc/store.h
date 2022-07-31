#ifndef STORE_H
#define STORE_H

#include <string>



class Store
{
    public:
        Store::Store(std::string name, std::string address);

    private:
        std::string m_name;
        std::string m_address;
        //listado de prendas
};

#endif