#include "pant.h"

Pant::Pant(PantTypeId typeId)
    : m_typeId(typeId)
{

}

Pant::~Pant()
{

}

std::string Pant::toString()
{
    //FIXME detalle pantalon
    return "detalle pantalon";
}

int Pant::stockItems(PantTypeId sleeveId)
{
    //FIXME stock items
    return 100;
}

void Pant::setPantTypeId(PantTypeId typeId)
{
    m_typeId = typeId;
}