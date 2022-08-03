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

float Shirt::getNetPrice(int unitPrice)
{
    float retValue = 1.0*unitPrice;
    if (ShirtSleeveId::Short == m_sleeveId)
    {
        retValue -= retValue*0.1;
    }
    if (ShirtCollarId::Mao == m_collarId)
    {
        retValue += retValue*0.03;
    }
    if (GarmentQualityId::Premium == m_qualityId)
    {
        retValue += retValue*0.3;
    }
    return retValue;
}

int Shirt::getStock()
{
    int retValue = 1000;

    if (m_sleeveId == ShirtSleeveId::Short)
    {
        retValue = 500;
        if (m_collarId == ShirtCollarId::Mao)
        {
            retValue = 200;
            if (m_qualityId == GarmentQualityId::Standard)
            {
                retValue = 100;
            }
            else if (m_qualityId == GarmentQualityId::Premium)
            {
                retValue = 100;
            }
        }
        else if (m_collarId == ShirtCollarId::Standard)
        {
            retValue = 300;
            if (m_qualityId == GarmentQualityId::Standard)
            {
                retValue = 150;
            }
            else if (m_qualityId == GarmentQualityId::Premium)
            {
                retValue = 150;
            }
        }
    }
    else if (m_sleeveId == ShirtSleeveId::Long)
    {
        retValue = 500;
        if (m_collarId == ShirtCollarId::Mao)
        {
            retValue = 150;
            if (m_qualityId == GarmentQualityId::Standard)
            {
                retValue = 75;
            }
            else if (m_qualityId == GarmentQualityId::Premium)
            {
                retValue = 75;
            }
        }
        else if (m_collarId == ShirtCollarId::Standard)
        {
            retValue = 350;
            if (m_qualityId == GarmentQualityId::Standard)
            {
                retValue = 175;
            }
            else if (m_qualityId == GarmentQualityId::Premium)
            {
                retValue = 175;
            }
        }
    }

    return retValue;
}

void Shirt::setCollarId(ShirtCollarId collarId)
{
    m_collarId = collarId;
}

void Shirt::setSleeveId(ShirtSleeveId sleeveId)
{
    m_sleeveId = sleeveId;
}