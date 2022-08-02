#include "salesQuotation.h"
#include "shirt.h"
#include "utils.h"

int SalesQuotation::m_nextId = 1;


SalesQuotation::SalesQuotation(std::string date, 
                               std::string time,
                               int sellerId,
                               std::string garment,
                               int unitPrice,
                               int quantity,
                               int totalPrice)
    : m_id(++m_nextId), m_date(date), m_time(time), m_sellerId(sellerId),
      m_garment(garment), m_unitPrice(unitPrice), m_quantity(quantity), 
      m_totalPrice(totalPrice)
      
{    

}

std::string SalesQuotation::toString()
{
    std::string str;
    str.append("Numero de identificacion: " + m_id);
    str.append("\n");
    str.append("Fecha y Hora de la cotizacion: " + m_date + " " + m_time);
    str.append("\n");
    str.append("Codigo del vendedor: " + m_sellerId);
    str.append("\n");
    str.append("Prenda cotizada: " + m_garment);
    str.append("\n");
    /* FIXME: formatear numero */
    str.append("Precio unitario: $" + m_unitPrice);
    str.append("\n");
    str.append("Cantidad de unidades cotizadas: " + m_quantity);
    str.append("\n");
    /* FIXME: formatear numero */
    str.append("Precio final: " + m_totalPrice);
    str.append(Utils::verticalSeparator());

    return str;
}