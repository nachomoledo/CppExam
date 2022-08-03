#include <expressSalesQuoting.h>
#include <userInputManager.h>
#include <seller.h>
#include <store.h>

int main() {
    UserInputManager userInputManager;
    Seller seller("Juan", "Perez");
    Store store("Mi Tienda", "Calle Falsa 123");
    ExpressSalesQuoting expressSalesQuoting(userInputManager, seller, store);
    expressSalesQuoting.run();
    return 0;
}