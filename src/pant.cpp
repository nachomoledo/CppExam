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

float Pant::getNetPrice(int unitPrice)
{
    float retValue = 1.0*unitPrice;
    if (PantTypeId::SlimFit == m_typeId)
    {
        retValue -= retValue*0.12;
    }
    if (GarmentQualityId::Premium == m_qualityId)
    {
        retValue += retValue*0.3;
    }

    return retValue;
}

int Pant::getStock()
{
    int retValue = 2000;
    if (m_typeId == PantTypeId::SlimFit)
    {
        retValue = 1500;
        if (m_qualityId == GarmentQualityId::Standard)
        {
            retValue = 750;
        }
        else if (m_qualityId == GarmentQualityId::Premium)
        {
            retValue = 750;
        }        
    }
    else if (m_typeId == PantTypeId::Standard)
    {
        retValue = 500;
        if (m_qualityId == GarmentQualityId::Standard)
        {
            retValue = 250;
        }
        else if (m_qualityId == GarmentQualityId::Premium)
        {
            retValue = 250;
        }        
    }

    return retValue;
}

void Pant::setPantTypeId(PantTypeId typeId)
{
    m_typeId = typeId;
}