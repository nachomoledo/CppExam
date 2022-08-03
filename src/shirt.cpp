#include "shirt.h"

Shirt::Shirt(GarmentQualityId qualityId, ShirtCollarId collarId, ShirtSleeveId sleeveId)
    : m_collarId(collarId), m_sleeveId(sleeveId)
{
    m_qualityId = qualityId;
}

Shirt::~Shirt()
{

}

std::string Shirt::toString()
{
    std::string str;
    str.append("Camisa");
    str.append(" - ");
    str.append((ShirtSleeveId::Long == m_sleeveId) ? "Manga Larga" 
             : (ShirtSleeveId::Short == m_sleeveId) ? "Manga Corta"
             : "No especificado");
    str.append(" - ");
    str.append((GarmentQualityId::Premium == m_qualityId) ? "Premium" 
            : (GarmentQualityId::Standard == m_qualityId) ? "Standard"
            : "No especificado");
    return str;
}

void Shirt::setCollarId(ShirtCollarId collarId)
{
    m_collarId = collarId;
}

void Shirt::setSleeveId(ShirtSleeveId sleeveId)
{
    m_sleeveId = sleeveId;
}

int Shirt::stockItems(ShirtCollarId collarId, ShirtSleeveId sleeveId, GarmentQualityId qualityId)
{
    int retValue = 1000;

    if (sleeveId == ShirtSleeveId::Short)
    {
        retValue = 500;
        if (collarId == ShirtCollarId::Mao)
        {
            retValue = 200;
            if (qualityId == GarmentQualityId::Standard)
            {
                retValue = 100;
            }
            else if (qualityId == GarmentQualityId::Premium)
            {
                retValue = 100;
            }
        }
        else if (collarId == ShirtCollarId::Standard)
        {
            retValue = 300;
            if (qualityId == GarmentQualityId::Standard)
            {
                retValue = 150;
            }
            else if (qualityId == GarmentQualityId::Premium)
            {
                retValue = 150;
            }
        }
    }
    else if (sleeveId == ShirtSleeveId::Long)
    {
        int retValue = 500;
        if (collarId == ShirtCollarId::Mao)
        {
            retValue = 150;
            if (qualityId == GarmentQualityId::Standard)
            {
                retValue = 75;
            }
            else if (qualityId == GarmentQualityId::Premium)
            {
                retValue = 75;
            }
        }
        else if (collarId == ShirtCollarId::Standard)
        {
            retValue = 350;
            if (qualityId == GarmentQualityId::Standard)
            {
                retValue = 175;
            }
            else if (qualityId == GarmentQualityId::Premium)
            {
                retValue = 175;
            }
        }
    }

    return retValue;
}
