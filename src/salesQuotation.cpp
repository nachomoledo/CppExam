#include "salesQuotation.h"
#include "shirt.h"
#include "utils.h"
#include <iostream>

int SalesQuotation::m_nextId = 1;


SalesQuotation::SalesQuotation(std::string date, 
                               std::string time,
                               int sellerId,
                               std::string garment,
                               int unitPrice,
                               int quantity,
                               float totalPrice)
    : m_id(m_nextId++), m_date(date), m_time(time), m_sellerId(sellerId),
      m_garment(garment), m_unitPrice(unitPrice), m_quantity(quantity), 
      m_totalPrice(totalPrice)
      
{    

}

std::string SalesQuotation::toString()
{
    std::string str;
    str.append("Numero de identificacion: " + std::to_string(m_id));
    str.append("\n");
    str.append("Fecha y Hora de la cotizacion: " + m_date + " " + m_time);
    str.append("\n");
    str.append("Codigo del vendedor: " + std::to_string(m_sellerId));
    str.append("\n");
    str.append("Prenda cotizada: " + m_garment);
    str.append("\n");
    str.append("Precio unitario: $" + std::to_string(m_unitPrice));
    str.append("\n");
    str.append("Cantidad de unidades cotizadas: " + std::to_string(m_quantity));
    str.append("\n");
    str.append("Precio final: $" + Utils::floatToString(m_totalPrice, 2));
    return str;
}