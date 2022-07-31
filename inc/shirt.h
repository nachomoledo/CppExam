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
        Shirt(ShirtCollarId collarId, ShirtSleeveId sleeveId);
        virtual ~Shirt();
        std::string toString(void);
        static int stockItems(ShirtCollarId collarId, ShirtCollarId sleeveId);

    private:
        ShirtCollarId m_collarId;
        ShirtSleeveId m_sleeveId;
};

#endif