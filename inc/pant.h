#ifndef PANT_H
#define PANT_H

#include "garment.h"
#include <string>

enum class PantTypeId
{
    Unspecified,
    Standard,
    SlimFit
};

class Pant : public Garment
{
    public:
        Pant(){};
        Pant(GarmentQualityId qualityId, PantTypeId pantType);
        virtual ~Pant();
        std::string toString(void) override;
        float getNetPrice(int unitPrice) override;
        int getStock(void) override;
        void setPantTypeId(PantTypeId typeId);

    private:
        PantTypeId m_typeId;
};

#endif