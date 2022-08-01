#ifndef SHIRT_H
#define SHIRT_H

#include "garment.h"
#include <string>

enum class ShirtCollarId
{
    Unspecified,
    Classic,
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
        Shirt(ShirtCollarId collarId = ShirtCollarId::Unspecified, ShirtSleeveId sleeveId = ShirtSleeveId::Unspecified);
        virtual ~Shirt();
        std::string toString(void) override;
        static int stockItems(ShirtCollarId collarId, ShirtCollarId sleeveId);
        void setCollarId(ShirtCollarId collarId);
        void setSleeveId(ShirtSleeveId sleeveId);

    private:
        ShirtCollarId m_collarId;
        ShirtSleeveId m_sleeveId;
};

#endif