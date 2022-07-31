#include <expressSalesQuoting.h>
#include <userInputManager.h>

int main() {
    UserInputManager userInputManager;
    ExpressSalesQuoting expressSalesQuoting(userInputManager);
    expressSalesQuoting.run();
    return 0;
}