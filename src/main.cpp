#include <homeScreen.h>
#include <iostream>

const std::string APP_NAME = "COTIZADOR EXPRESS";
const std::string SCREEN_NAME = "MENU PRINCIPAL";
const std::string STORE_NAME = "STORE NAME";
const std::string STORE_ADDRESS = "STORE ADDRESS";
const std::string SELLER_NAME = "SELLER NAME";
const std::string SELLER_SURNAME = "SELLER SURNAME";
const std::string SELLER_ID = "0001";

int main() {
    HomeScreen homeScreen(APP_NAME + " - " + SCREEN_NAME, STORE_NAME, STORE_ADDRESS, SELLER_NAME, SELLER_SURNAME, SELLER_ID);
    homeScreen.addOption(1, "Historial de Cotizaciones");
    homeScreen.addOption(2, "Realizar Cotización");
    homeScreen.addOption(3, "Salir");
    homeScreen.print();
    return 0;
}