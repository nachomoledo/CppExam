#ifndef GARMENT_H
#define GARMENT_H

enum class GarmentTypeId
{
    Unspecified,
    Shirt,
    Pants
};

enum class QualityId
{
    Unspecified,
    Standard,
    Premium
};


class Garment
{
    private:
        GarmentTypeId m_type;
        QualityId m_quality;
        int m_unitPrice;
        int m_stockQuantity;
};

#endif 