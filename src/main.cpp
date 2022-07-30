#include <uiManager.h>

int main() {
    UserInputManager userInputManager;
    UIManager uiManager(userInputManager);
    userInputManager.getUserInput();

    return 0;
}