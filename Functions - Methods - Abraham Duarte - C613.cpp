#include <iostream>
#include <clocale>
using namespace std;

/* Global Variables, Functions and Methods */

int option, rows, columns, i = 0, j = 0, e = 0, f = 0, total_products, IVA[100][100], quantity[100][100], IVA_accumulator = 0, food_accumulator = 0, drinks_accumulator = 0, cleaning_accumulator = 0, electronics_accumulator = 0, category, categories[100][100], type;
bool state = true;
string name, names[100][100], food_category[100][100], drinks_category[100][100], cleaning_category[100][100], electronics_category[100][100];
double prices[100][100], cheaper_accumulator = 0, expensive_accumulator = 0, price;
void menu(); // Method
int matrix(int rows, int columns); // Function
void saved_values(); // Method
void add_products(); 
void modify_products();
void list_products();
void summary();
bool goodbye(); // function

int main() {
	setlocale(LC_ALL, "Spanish");
	cout << "### SISTEMA DE INVENTARIO ###\n";
	do {
		menu();
		cin >> option;
		system("cls");
		switch (option) {
			case 1:
				add_products();
			break;
			case 2:
				modify_products();
			break;
			case 3:
				list_products();
			break;
			case 4:
				summary();
			break;
			case 5:
				goodbye();
			break;
			default:
				cout << "\nError, opción no valida";
			break;
	}
	}
	while (state == true);
}

void menu() {
	cout << "\n[1] Registrar Productos";
	cout << "\n[2] Modificar Producto";
	cout << "\n[3] Listado De Productos";
	cout << "\n[4] Estadísticas";
	cout << "\n[5] Salir";
	cout << endl;
}
	
void add_products() {
	cout << "\n### AGREGAR PRODUCTOS ###";
	cout << "\nIndique la cantidad de filas que quiere ingresar: ";
	cin >> rows;
	cout << "\nAhora, indique la cantidad de columnas que quiere ingresar: ";
	cin >> columns;
	total_products = columns * rows;
	names[1][1] = names[rows][columns];
	prices[1][1] = prices[rows][columns];
	quantity[1][1] = quantity[rows][columns];
	categories[1][1] = categories[rows][columns];
	IVA[1][1] = IVA[rows][columns];
	food_category[1][1] = food_category[rows][columns];
	drinks_category[1][1] = drinks_category[rows][columns];
	cleaning_category[1][1] = cleaning_category[rows][columns];
	electronics_category[1][1] = electronics_category[rows][columns];
	cout << "\nTotal de elementos indicados: " << total_products;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "\nNombre [" << i << "][" << j << "]: ";
			cin >> name;
			name = names[i][j];
			cout << "\nPrecio: ";
			cin >> price;
			if (i == 0 && j == 0) {
				cheaper_accumulator = price;
				expensive_accumulator = price;
			}
			if (expensive_accumulator < price) {
				expensive_accumulator = price;
			}
			if (cheaper_accumulator > price) {
				cheaper_accumulator = price;
			}
			price = prices[i][j];
			cout << "\nCantidad: ";
			cin >> quantity[i][j];
			cout << "\nTipo de producto:\nComestible = 1\nBebida = 2\nLimpieza = 3\nElectrónica = 4" << endl;
			cin >> category;
			switch (category) {
				case 1:
					food_accumulator = food_accumulator + 1;
					food_category[i][j] = name;
				break;
				case 2:
					drinks_accumulator = drinks_accumulator + 1;
					names[i][j] = drinks_category[i][j];
				break;
				case 3:
					cleaning_accumulator = cleaning_accumulator + 1;
					names[i][j] = cleaning_category[i][j];
				break;
				case 4:
					electronics_accumulator = electronics_accumulator + 1;
					names[i][j] = electronics_category[i][j];
				break;
				default:
				break;
			} 
			category = categories[i][j]; 
			cout << "\nPaga Impuesto IVA?\nSi = 1\nNo = 0\n";
			cin >> IVA[i][j];
		}
	};
	system("pause");
	system("cls");
}
	
void modify_products() {
	cout << "\n### MODIFICAR PRODUCTOS ###";
	for (int i = 0; i < rows; i++) {
		cout << "----------------------------------------------------------------";
		cout << endl;
		for (int j = 0; j < columns; j++) {
			cout << "|  [ " << i << "][" << j << "] " << names[i][j] << "  |";
		}
		cout << endl;
		cout << "----------------------------------------------------------------";
		cout << endl;
	}
	cout << "\nEl primer dígito indica la fila, el segundo dígito indica la columna.\nPor favor, indique el número de fila del elemento que desea modificar: ";
	cin >> e;
	cout << "\nIndique el numero de columna al que pertenece dicho elemento: ";
	cin >> f;
	cout << "\nNombre [" << e << "][" << f << "]: ";
	cin >> names[e][f];
	cout << "\nPrecio: ";
	cin >> prices[e][f];
	cout << "\nCantidad: ";
	cin >> quantity[e][f];
	cout << "\nTipo de producto: ";
	cin >> categories[e][f];
	cout << "\nPaga Impuesto IVA?\nSi = 1\nNo = 0\n";
	cin >> IVA[e][f];
	system("pause");
	system("cls");
}
	
void list_products() {
	cout << "\n### LISTADO DE PRODUCTOS ###";
	cout << "\n----------------------------------\n";
	for (int i = 0; i < rows; i++) {
		cout << "----------------------------------------------------------------";
		cout << endl;
		for (int j = 0; j < columns; j++) {
			cout << "|  [" << i << "][" << j << "] " << names[i][j] << "  |";
		}
		cout << endl;
		cout << "----------------------------------------------------------------";
		cout << endl;
	}
	system("pause");
	system("cls");
	}
	
void summary() {
	cout << "\n### ESTADÍSTICAS ###";
	cout << "\nTotal de productos: " << total_products;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			if (IVA[i][j] == 1) {
				IVA_accumulator = IVA_accumulator + 1;
			}
		}
	}
	cout << "\nTotal de productos con Impuesto IVA: " << IVA_accumulator << " artículos";
	cout << "\nTotal de productos por tipo:\n[1] Comestibles: " << food_accumulator;
	cout << "\n[2] Bebidas: " << drinks_accumulator;
	cout << "\n[3] Limpieza: " << cleaning_accumulator;
	cout << "\n[4] Electrónicos: " << electronics_accumulator;
	cout << "\nProducto más económico: " << cheaper_accumulator;
	cout << "\nProducto más costoso: " << expensive_accumulator;
	cout << "\nIndique el tipo de producto que quiere ver resumido..\n[1] Comestibles\n[2] Bebidas\n[3] Limpieza\n[4] Electrónicos\n";
	cin >> type;
	switch (type) {
		case 1:
			cout << "\n### COMESTIBLES ###";
			for (int i = 0; i < rows; i++) {
				cout << "\n----------------------------------------------\n";
				cout << endl;
				for (int j = 0; j < columns; j++) {
					cout << "|  [" << i << "][" << j << "] " << food_category[i][j] << "  |";
				}
				cout << endl;
				cout << "\n----------------------------------------------";
			}
		break;
		case 2:
			cout << "\n### BEBIDAS ###";
			for (int i = 0; i < rows; i++) {
				cout << "----------------------------------------------------------------";
				cout << endl;
				for (int j = 0; j < columns; j++) {
					cout << "|  [" << i << "][" << j << "] " << drinks_category[i][j] << "  |";
				}
				cout << endl;
				cout << "----------------------------------------------------------------";
			}
		break;
		case 3:
			cout << "\n### LIMPIEZA ###";
			for (int i = 0; i < rows; i++) {
				cout << "----------------------------------------------------------------";
				cout << endl;
				for (int j = 0; j < columns; j++) {
					cout << "|  [" << i << "][" << j << "] " << cleaning_category[i][j] << "  |";
				}
				cout << endl;
				cout << "----------------------------------------------------------------";
			}
		break;
		case 4:
			cout << "\n### ELECTRÓNICOS ###";
			for (int i = 0; i < rows; i++) {
				cout << "----------------------------------------------------------------";
				cout << endl;
				for (int j = 0; j < columns; j++) {
					cout << "|  [" << i << "][" << j << "] " << electronics_category[i][j] << "  |";
				}
				cout << endl;
				cout << "----------------------------------------------------------------";
			}
		break;
		default:
			cout << "\nError";
		break;
	}
	system("pause");
	system("cls");
}
	
bool goodbye() {
	cout << "\nSaliendo del sistema..";
	state = false;
	return state;
}
