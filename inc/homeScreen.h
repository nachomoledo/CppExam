#ifndef HOME_SCREEN
#define HOME_SCREEN

#include "baseScreen.h"
#include <list>

class HomeScreen : public BaseScreen
{
    public:
        HomeScreen();
        virtual ~HomeScreen();
        HomeScreen(std::string title,
                   std::string storeName,
                   std::string storeAddress,
                   std::string sellerName,
                   std::string sellerSurname,
                   std::string sellerId);

    protected:
        std::string content(void) override;

    private:
        std::string m_storeName;
        std::string m_storeAddress;
        std::string m_sellerName;
        std::string m_sellerSurname;
        std::string m_sellerId;
};

#endif