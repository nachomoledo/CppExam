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

int Shirt::stockItems(ShirtCollarId collarId, ShirtCollarId sleeveId)
{
    //FIXME: stock items camisa
    return 200;
}
