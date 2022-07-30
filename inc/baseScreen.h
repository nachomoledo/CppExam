#include <string>

#define WIDTH 80

class BaseScreen
{
    public:
        BaseScreen(std::string title = "");
        virtual ~BaseScreen();
        void print(void);
    protected:
        std::string m_title;
        static std::string verticalSeparator(void);
        static std::string horizontalSeparator(void);
        virtual std::string content(void) = 0;
};