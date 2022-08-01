#include "shirt.h"

Shirt::Shirt(ShirtCollarId collarId, ShirtSleeveId sleeveId)
    : m_collarId(collarId), m_sleeveId(sleeveId)
{

}

Shirt::~Shirt()
{

}

std::string Shirt::toString()
{
    //FIXME detalle camisa
    return "detalle camisa";
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
