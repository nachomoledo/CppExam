#include "pant.h"

Pant::Pant(GarmentQualityId qualityId, PantTypeId typeId)
    : m_typeId(typeId)
{
    m_qualityId = qualityId;
}

Pant::~Pant()
{

}

std::string Pant::toString()
{
    std::string str;
    str.append("Pantalon");
    str.append(" - ");
    str.append((PantTypeId::Standard == m_typeId) ? "Standard" 
             : (PantTypeId::SlimFit == m_typeId) ? "Chupin"
             : "No especificado");
    return str;
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