#ifndef PANT_H
#define PANT_H

#include "garment.h"
#include <string>

enum class PantTypeId
{
    Unspecified,
    Classic,
    SlimFit
};

class Pant : public Garment
{
    public:
        Pant(PantTypeId pantType);
        virtual ~Pant();
        std::string toString(void);
        static int stockItems(PantTypeId sleeveId);

    private:
        PantTypeId m_pantType;
};

#endif