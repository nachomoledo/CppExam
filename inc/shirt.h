#ifndef SHIRT_H
#define SHIRT_H

#include "garment.h"
#include <string>

enum class ShirtCollarId
{
    Unspecified,
    Standard,
    Mao
};

enum class ShirtSleeveId
{
    Unspecified,
    Short,
    Long

};

class Shirt : public Garment
{
    public:
        Shirt(){};
        Shirt(GarmentQualityId qualityId, ShirtCollarId collarId, ShirtSleeveId sleeveId);
        virtual ~Shirt();
        std::string toString(void) override;
        static int stockItems(ShirtCollarId collarId, ShirtSleeveId sleeveId, GarmentQualityId qualityId);
        void setCollarId(ShirtCollarId collarId);
        void setSleeveId(ShirtSleeveId sleeveId);

    private:
        ShirtCollarId m_collarId;
        ShirtSleeveId m_sleeveId;
};

#endif