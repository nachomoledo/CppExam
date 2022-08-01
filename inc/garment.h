#ifndef GARMENT_H
#define GARMENT_H

#include <string>

enum class QualityId
{
    Unspecified,
    Standard,
    Premium
};

class Garment
{
    public:
        QualityId getQuaility(void);
        void setQualityId(QualityId qualityId);
        virtual std::string toString(void) = 0;

    private:
        QualityId m_qualityId;
        int m_unitPrice;
        int m_stockQuantity;
};

#endif 