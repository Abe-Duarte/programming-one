#include <iostream>
using namespace std;
bool state = true, discount_state_bool;
int option, quantity, discount, amount, i = 0, IVA, total_amount_products = 0, higher_quantity_product = 0, discount_accumulator = 0, discount_state;
string product_name, code;
double price = 0, exchange, brute_price, net_price, brute_product = 0, brute_product_accumulator = 0, net_product_accumulator = 0, higher_price = 0, lower_price;
int main () {
    cout << "\nIngrese la tasa de cambio actual: ";
    cin >> exchange;
    cout << "\nIngrese la cantidad de IVA que utilizará: ";
    cin >> IVA;
    do {
        cout << "\n[1] Agregar articulos";
        cout << "\n[2] Estadisticas";
        cout << "\n[3] Estadisticas (Bs)";
        cout << "\n[4] Limpiar registro";
        cout << "\n[5] Configuraciones";
        cout << "\n[6] Salir";
        cout << "\nIngrese la opción deseada.. ";
        cin >> option;
        switch (option) {
            case 1:
                // system("cls");
                lower_price = price;
                cout << "### AGREGAR ARTICULOS ###";
                cout << "\nIngrese la cantidad de articulos que desea agregar: ";
                cin >> amount;
                for (i; i < amount; i++) {
                    cout << "\nNombre: ";
                    cin >> product_name;
                    cout << "\nCodigo: ";
                    cin >> code;
                    cout << "\nPrecio: ";
                    cin >> price;
                    if (higher_price < price) {
                        higher_price = price;
                    }
                    if (lower_price >= price) {
                        lower_price = price;
                        // Corregir ésta sentencia
                    }
                    cout << "\nCantidad: ";
                    cin >> quantity;
                    if (higher_quantity_product < quantity) {
                        higher_quantity_product = quantity;
                    }
                    cout << "\nSe le aplica descuento?\nSi = 1\nNo = 0\n";
                    cin >> discount_state;
                    if (discount_state == 1) {
                        discount_state_bool = true;
                    }
                    else if (discount_state == 0) {
                        discount_state_bool = false;
                    }
                    if (discount_state_bool == true) {
                        do {
                            cout << "\nDescuento: ";
                            cin >> discount;
                            do {
                                if (discount < 0 || discount > 100) {
                                    cout << "\nError: Debe de ingresar una cantidad de descuento entre 1% y 100%";
                                    cout << "\nDescuento: ";
                                    cin >> discount;
                                }
                                else if (discount > 0 && discount <= 100) {
                                    break;
                                }
                            }
                        while (discount < 0 || discount > 100);
                    }
                    while (discount < 0 && discount > 100);
                    if (discount > 0) {
                        discount_accumulator = discount_accumulator + i;
                        }   
                    }
                    total_amount_products = total_amount_products + quantity;
                    brute_product = quantity * price;
                    brute_product_accumulator = brute_product + brute_product_accumulator;
                    net_product_accumulator = brute_product_accumulator + (brute_product_accumulator / 100) * IVA;
                    // system("cls");
                }
            break;
            case 2:
                cout << "\n### ESTADÍSTICAS ###";
                cout << "\nPrecio bruto de todos los artículos: " << brute_product_accumulator << "$";
                cout << "\nPrecio neto de todos los artículos: " << net_product_accumulator << "$";
                cout << "\nCantidad total de artículos ingresados: " << total_amount_products << " artículos";
                cout << "\nArtículo con la mayor cantidad de existencia: " << higher_quantity_product << " artículos";
                cout << "\nArtículo con la menor cantidad de existencia: FALTA";
                cout << "\nArtículo más costoso: " << higher_price;
                cout << "\nArticulo más barato: FALTA";
                cout << "\nCantidad de articulos con descuento: " << discount_accumulator << " artículos";
            break;
            default:
                // system("cls");
                cout << "Error: Debe de ingresar alguna opción valida";
            break;
            cout << "\n[1] Agregar articulos";
        cout << "\n[2] Estadisticas";
        cout << "\n[3] Estadisticas (Bs)";
        cout << "\n[4] Limpiar registro";
        cout << "\n[5] Configuraciones";
        cout << "\n[6] Salir";
        cout << "\nIngrese la opción deseada.. ";
        cin >> option;
        }
    }
    while (state = true);
}

// Arranco el contador de valor menor = al valor ingresado primeramente (no en 0). Luego, comparo si el valor primario es menor o mayor que los demás valores