#ifndef SALES_QUOTATION_H
#define SALES_QUOTATION_H

#include "garment.h"
#include <string>
#include <memory>

class SalesQuotation
{
    public:
        SalesQuotation(std::string date, 
                       std::string time,
                       int sellerId,
                       std::string garment,
                       int unitPrice,
                       int quantity,
                       float totalPrice);
        std::string toString(void);

    private:
        static int m_nextId;
        int m_id;
        std::string m_date;
        std::string m_time;
        int m_sellerId;
        std::string m_garment;
        int m_unitPrice;
        int m_quantity;
        float m_totalPrice;
};

#endif