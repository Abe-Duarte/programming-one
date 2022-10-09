#include <iostream>
using namespace std;
bool state = true;
int option, quantity, discount, accumulator = 0, i = 0;
string product_name, code;
double price;
int main () {
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
                cout << "### AGREGAR ARTICULOS ###";
                cout << "\nIngrese la cantidad de articulos que desea agregar: ";
                cin >> accumulator;
                for (i; i < accumulator; i++) {
                    cout << "\nNombre: ";
                    cin >> product_name;
                    cout << "\nCodigo: ";
                    cin >> code;
                    cout << "\nPrecio: ";
                    cin >> price;
                    cout << "\nCantidad: ";
                    cin >> quantity;
                    cout << "\nDescuento: ";
                    cin >> discount;
                    // system("cls");
                }
            break;
            default:
                // system("cls");
                cout << "Error: Debe de ingresar alguna opción valida";
            break;
        }
    }
    while (state = true);
}