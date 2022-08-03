#ifndef GARMENT_H
#define GARMENT_H

#include <string>

enum class GarmentQualityId
{
    Unspecified,
    Standard,
    Premium
};

class Garment
{
    public:
        GarmentQualityId getQuaility(void);
        void setQualityId(GarmentQualityId qualityId);
        virtual std::string toString(void) = 0;

    protected:
        GarmentQualityId m_qualityId;
    
    private:
        int m_unitPrice;
        int m_stockQuantity;
};

#endif 