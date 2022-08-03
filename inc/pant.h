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
        static int stockItems(PantTypeId typeId, GarmentQualityId qualityId);
        void setPantTypeId(PantTypeId typeId);

    private:
        PantTypeId m_typeId;
};

#endif