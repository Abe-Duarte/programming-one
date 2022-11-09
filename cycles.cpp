#include <iostream>
#include <clocale>
#include <math.h>
using namespace std;
bool state = true, discount_state_bool;
int option, quantity, discount, amount, i = 0, IVA, total_amount_products = 0, higher_quantity_product = 0, lower_quantity_product, discount_accumulator = 0, discount_state;
string product_name, code;
double price = 0, exchange, brute_price, net_price, brute_product = 0, brute_product_accumulator = 0, net_product_accumulator = 0, higher_price = 0, lower_price;

int main () {
    setlocale(LC_ALL, "Spanish");
    cout << "\nIngrese la tasa de cambio actual: ";
    cin >> exchange;
    cout << "\nIngrese la cantidad de IVA que utilizara: ";
    cin >> IVA;
    do {
        cout << "\n[1] Agregar articulos";
        cout << "\n[2] Estadisticas";
        cout << "\n[3] Estadisticas (Bs)";
        cout << "\n[4] Limpiar registro";
        cout << "\n[5] Configuraciones";
        cout << "\n[6] Salir";
        cout << "\nIngrese la opcion deseada.. ";
        cin >> option;
        switch (option) {
            case 1:
                system("cls");
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
                    if(i == 0) {
                        higher_price = price;
                        lower_price = price;
                    }
                    if (higher_price < price) {
                        higher_price = price;
                    }
                    if (lower_price > price) {
                        lower_price = price;
                    }
                    cout << "\nCantidad: ";
                    cin >> quantity;
                    total_amount_products = total_amount_products + quantity;
                    brute_product = quantity * price;
                    brute_product_accumulator = brute_product + brute_product_accumulator;
                    if(i == 0) {
                        higher_quantity_product = quantity;
                        lower_quantity_product = quantity;
                    }
                    if (higher_quantity_product < quantity) {
                        higher_quantity_product = quantity;
                    }
                    if (lower_quantity_product > quantity) {
                        lower_quantity_product = quantity;
                    }
                    cout << "\nSe le aplica descuento?\nSi = 1\nNo = 0\n";
                    cin >> discount_state;
                    if (discount_state == 1) {
                        discount_state_bool = true;
                        discount_accumulator = discount_accumulator + 1;
                    }
                    else if (discount_state == 0) {
                        discount_state_bool = false;
                    } 
					system("cls"); 
                    }
                    net_product_accumulator = brute_product_accumulator + (brute_product_accumulator / 100) * IVA;
                    system("cls");
            break;
            case 2:
                cout << "\n### ESTADISTICAS ###";
                cout << "\nTasa de Impuesto IVA: " << IVA << "%";
                cout << "\nPrecio bruto de todos los articulos: " << brute_product_accumulator << "$";
                net_product_accumulator = brute_product_accumulator + (brute_product_accumulator / 100) * IVA;
				cout << "\nPrecio neto de todos los articulos: " << net_product_accumulator << "$";
                cout << "\nCantidad total de articulos ingresados: " << total_amount_products << " articulos";
                cout << "\nArticulo con la mayor cantidad de existencia: " << higher_quantity_product << " articulos";
                cout << "\nArticulo con la menor cantidad de existencia: " << lower_quantity_product << " articulos";
                cout << "\nArticulo mas costoso: " << higher_price;
                cout << "\nArticulo mas barato: " << lower_price;
                cout << "\nCantidad de articulos con descuento: " << discount_accumulator << " articulos";
                system("pause");
            break;
            case 3:
            	cout << "\n### ESTADISTICAS (Bs) ###";
            	cout << "\nTasa de Impuesto IVA: " << IVA << "%";
            	cout << "\nTasa de cambio: " << exchange << " Bs";
            	cout << "\nPrecio bruto de todos los articulos: " << brute_product_accumulator * exchange << " Bs";
                net_product_accumulator = brute_product_accumulator + (brute_product_accumulator / 100) * IVA;
			    cout << "\nPrecio neto de todos los articulos: " << net_product_accumulator * exchange << " Bs";
                cout << "\nCantidad total de articulos ingresados: " << total_amount_products << " articulos";
                cout << "\nArticulo con la mayor cantidad de existencia: " << higher_quantity_product << " articulos";
                cout << "\nArticulo con la menor cantidad de existencia: " << lower_quantity_product;
                cout << "\nArticulo mas costoso: " << higher_price * exchange << " Bs";
                cout << "\nArticulo mas barato: " << lower_price * exchange << " Bs";
                cout << "\nCantidad de articulos con descuento: " << discount_accumulator << " articulos";
            break;
            case 4:
            	cout << "\n### LIMPIEZA DE REGISTRO ###";
            	brute_product_accumulator = 0;
                net_product_accumulator = 0;
                total_amount_products = 0;
                higher_quantity_product = 0;
        		higher_price = 0;
                discount_accumulator = 0;
        		cout << "\nNo hay articulos en existencia.. Presione cualquier tecla para continuar";
        		system("pause");
            break;
            case 5:
            	cout << "\n### CONFIGURACIONES (Bs/$ e IVA)";
            	cout << "\nIngrese nueva tasa de canbio: ";
            	cin >> exchange;
            	cout << "\nIngrese nuevo valor de Impuesto IVA: ";
            	cin >> IVA;
            break;
            case 6:
            	cout << "\n### SALIENDO DEL SISTEMA ###";
            	cout << "\nPresione cualquier tecla para salir...";
            	system("pause");
            	state = false;
            break;
            default:
                cout << "Error: Debe de ingresar alguna opción valida";
            break;
    	}
    }
    while (state = true);
} 
