#include <iostream>
#include <clocale>
using namespace std;
string name[100], code[100];
double exchange, price[100], net_products = 0, total_brute_price = 0, total_brute_accumulator = 0, higher_price, lower_price;
int option, n = 0, i = 0, IVA, discount, quantity[100], currency, e, total_amount_products, quantity_accumulator = 0, no_stock_accumulator = 0, higher_quantity_accumulator = 0, lower_quantity_accumulator = 0, higher_quantity = 0, lower_quantity = 0;
int main () {
	setlocale(LC_ALL, "Spanish");
	cout << "### SISTEMA DE INVENTARIO###";
	cout << "\nIngrese la tasa de cambio actual: ";
	cin >> exchange;
	cout << "\nIngrese la cantidad de IVA a calcular: ";
	cin >> IVA;
	cout << "\nIngrese el descuento general de los productos: ";
	cin >> discount;
	do {
		system("cls");
		cout << "\n[1] AGREGAR PRODUCTOS";
		cout << "\n[2] EDITAR PRODUCTOS";
		cout << "\n[3] LISTADO DE PRODUCTOS";
		cout << "\n[4] ESTADÍSTICAS";
		cout << "\n[5] CONFIGURACIONES";
		cout << "\n[6] SALIR";
		cout << "\nIndique una opción.. ";
		cin >> option;
		switch (option) {
			case 1: 
				system("cls");
				cout << "\n### AGREGAR PRODUCTOS ###";
				cout << "\nIndique la cantidad de productos que desea agregar: ";
				cin >> n;
				system("cls");
				for (i = 0; i < n; i++) {
					cout << "\nNombre: ";
					cin >> name[i];
					cout << "\nCodigo: ";
					cin >> code[i];
					cout << "\nCantidad: ";
					cin >> quantity[i];
					if (quantity[i] == 0) {
						no_stock_accumulator = no_stock_accumulator + 1;
						
					}
					if(i == 0) {
                        higher_price = price;
                        lower_price = price;
                    }
                    if (higher_quantity < quantity[i]) {
                        higher_quantity = quantity[i];
                    }
                    if (lower_quantity > quantity[i]) {
                        lower_quantity = quantity[i];
                    }
					quantity_accumulator = quantity_accumulator + quantity[i];
					cout << "\nPrecio: ";
					cin >> price[i];
					if (i == 0) {
                        higher_price = price[i];
                        lower_price = price[i];
                    }
                    if (higher_price < price[i]) {
                        higher_price = price[i];
                    }
                    if (lower_price > price[i]) {
                        lower_price = price[i];
                    }
					total_brute_price = price[i] * quantity[i];
					total_brute_accumulator = total_brute_accumulator + total_brute_price;
					cout << endl;
					system("pause");
					system("cls");
				}
			break;
			case 2:
				{
				system("cls");
				cout << "### EDITAR PRODUCTOS ###";
				cout << "\nLista completa de productos: ";
				for (int i = 0; i < n; i++) {
					cout << "\n[" << i << "] " << name[i];
				}
				cout << endl;
				cout << "\nIndique el producto que quiere editar: ";
				cin >> e;
				cout << "\nNombre: ";
				cin >> name[e];
				cout << "\nCodigo: ";
				cin >> code[e];
				cout << "\nCantidad: ";
				cin >> quantity[e];
				cout << "\nPrecio: ";
				cin >> price[e];
				cout << endl;
				system("pause");
				}
			break;
			case 3: 
				system("cls");
				cout << "### LISTADO DE PRODUCTOS ###";
				cout << "\nEn qué moneda desea ver el listado?\n1 = Dólares ($)\n2 = Bolívares (Bs)\n";
				cin >> currency;
				if (currency == 1) {
					system("cls");
					for (int i = 0; i < n; i++) {
						cout << "\n [" << i << "] " << name[i] << ": " << price[i] << "$";
					}
					cout << endl;
					system("pause");
				}
				else if (currency == 2) {
					system("cls");
					for (int i = 0; i < n; i++) {
						cout << "\n [" << i << "] " << name[i] << ": " << price[i] * exchange << "Bs";
					}
					cout << endl;
					system("pause");
				}
			break;
			case 4:
				{
				system("cls");
				cout << "### ESTADÍSTICAS ###";
				cout << "\nDesea mostrar los resultados en dólares ($) o en bolívares (Bs)?\nDólares = 1\nBolívares = 2\n";
				cin >> currency;
				if (currency == 1) {
					cout << "\nTasa de Impuesto IVA: " << IVA << "%";
					cout << "\nTotal bruto: " << total_brute_accumulator << " $";
					net_products = ((total_brute_accumulator / 100) * IVA) + total_brute_accumulator;
					cout << "\nTotal neto: " << net_products << " $";
					cout << "\nCantidad total de productos: " << quantity_accumulator;
					cout << "\nCantidad de productos en sistema: " << n;
					cout << "\nProductos sin stock: " << no_stock_accumulator;
					cout << "\nProducto con mayor cantidad de unidades: " << higher_quantity;
					cout << "\nProducto con menor cantidad de unidades: " << lower_quantity;
					cout << "\nProducto más costoso: " << higher_price << "$";
					cout << "\nProducto más económico: " << lower_price << "$";
					cout << endl;
					system("pause");
				}
				else if (currency == 2) {
					cout << "\nTasa de cambio ($/Bs): " << exchange;
					cout << "\nTasa de Impuesto IVA: " << IVA << "%";
					cout << "\nTotal bruto: " << total_brute_accumulator * exchange << " Bs";
					net_products = (((total_brute_accumulator / 100) * IVA) + total_brute_accumulator) * exchange; 
					cout << "\nTotal neto: " << net_products << " Bs";
					cout << "\nCantidad total de productos: " << quantity_accumulator;
					cout << "\nCantidad de productos en sistema: " << n;
					cout << "\nProductos sin stock: " << no_stock_accumulator;
					cout << "\nProducto con mayor cantidad de unidades: " << higher_quantity;
					cout << "\nProducto con menor cantidad de unidades: " << lower_quantity;
					cout << "\nProducto más costoso: " << higher_price * exchange<< " Bs";
					cout << "\nProducto más económico: " << lower_price * exchange << " Bs";
					cout << endl;
					system("pause");
				}
				}
			break;
			case 5:
				system("cls");
				cout << "### CONFIGURACIONES ###";
				cout << "\nIngrese la nueva tasa de cambio: ";
				cin >> exchange;
				cout << "\nIngrese nueva tasa de Impuesto IVA: ";
				cin >> IVA;
				cout << "\nIngrese nueva cantidad de descuento general a todos los productos: ";
				cin >> discount;
				cout << endl;
				system("pause");
			break;
			default:
				cout << "Error.. ";
			break;
			}
	}	
	while (option != 6);
}
