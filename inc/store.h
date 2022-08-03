#ifndef STORE_H
#define STORE_H

#include "garment.h"
#include "seller.h"
#include <string>
#include <list>

class Store
{
    public:
        Store(std::string name, std::string address);
        std::string getName();
        std::string getAddress();
        void addSeller(Seller*);

    private:
        std::string m_name;
        std::string m_address;
        std::list<Garment*> m_garmentList;
        std::list<Seller*> m_sellerList;
};

#endif