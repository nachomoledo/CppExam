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
        Pant(PantTypeId pantType = PantTypeId::Unspecified);
        virtual ~Pant();
        std::string toString(void) override;
        static int stockItems(PantTypeId sleeveId);
        void setPantTypeId(PantTypeId typeId);

    private:
        PantTypeId m_typeId;
};

#endif