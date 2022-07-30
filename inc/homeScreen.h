#include "baseScreen.h"
#include <list>
#include <vector>

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
                   std::string sellerId,
                   std::list<std::string> optionList = {}
                   );
        void addOption(int number, std::string option);

    protected:
        std::string content(void) override;

    private:
        std::string m_storeName;
        std::string m_storeAddress;
        std::string m_sellerName;
        std::string m_sellerSurname;
        std::string m_sellerId;
        std::list<std::string> m_optionList;
};