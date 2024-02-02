#include <iostream>
using namespace std;
void ejercicio1() {
	// inicializando variables 
	int* arreglo1 = NULL;
	bool tamcorrecto = false;
	int tam = 0;
	// Validando que el tamaño sea el correcto
	while (!tamcorrecto) {
		cout << "Ingrese el tamano" << endl;
		tam = 0;
		cin >> tam;
		if (tam >= 5) {
			tamcorrecto = true;
		}
		else {
			cout << "El tamano debe ser mayor a 5" << endl;
		}
	}
	// Mas validaciones de entrada de datos del usuario, donde si el numero ingresado es entre 1 y 15
	arreglo1 = new int[tam];
	bool vali = false;
	int num;
	for (int i = 0; i < tam; i++) {
		vali = false;
		while (!vali) {
			cout << "Ingrese el numero para almacenar dentro del arreglo" << endl;
			num = 0;
			cin >> num;
			if (num > 0 && num < 16) {
				arreglo1[i] = num;
				vali = true;
			}
			else {
				cout << "El numero debe ser entre 1 y 15" << endl;
			}
		}
	}
	// Inicializando mas variables 
	int contador = 0;
	int contador2 = 0;
	int* arreglo2 = NULL;
	arreglo2 = new int[tam];
	// haciendo logica necesaria para poder agregar el numero 7 al final del arreglo 
	for (int i = 0; i < tam; i++) {
		if (arreglo1[i] != 7) {
			arreglo2[contador] = arreglo1[i];
			contador++;
		}
		//  si el numero dentro del arreglo es diferente de 7, va a agregar los datos dentro del nuevo arreglo
		else {
			contador2++;
			//  Este contador me confirma si hay un 7 dentro del programa para poder hacer una validacion
		}
	}
	if (contador2 == 0) {
		cout << "Vale mas que no esta el 7, porque no es optimo!" << endl;
		cout << "Arreglo " << endl;
		for (int i = 0; i < tam; i++)
		{
			if (i == 0) {
				cout << "[" << arreglo1[i] << ",";
			}
			else if (i < tam - 1) {
				cout << arreglo1[i] << ",";
			}
			else {
				cout << arreglo1[i] << "]" << endl;
			}

		}
	}
	// si no hay 7 entonces solo va a imprimir el arreglo normal
	else {
		// terminando de llenar el arreglo si encontro algun 7
		while (contador < tam) {
			arreglo2[contador] = 7;
			contador++;
		}
		cout << "Arreglo antes" << endl;
		for (int i = 0; i < tam; i++)
		{
			if (i == 0) {
				cout << "[" << arreglo1[i] << ",";
			}
			else if (i < tam - 1) {
				cout << arreglo1[i] << ",";
			}
			else {
				cout << arreglo1[i] << "]" << endl;
			}

		}
		cout << "Arreglo despues" << endl;
		for (int i = 0; i < tam; i++)
		{
			if (i == 0) {
				cout << "[" << arreglo2[i] << ",";
			}
			else if (i < tam - 1) {
				cout << arreglo2[i] << ",";
			}
			else {
				cout << arreglo2[i] << "]" << endl;
			}
		}
	}
	delete[] arreglo1;
	delete[] arreglo2;
}
void ejercicio2()
{
	int* arreglo1 = NULL;
	bool tamcorrecto = false;
	int tam = 0;
	// Validando que el tamaño sea el correcto y el numero objetivo 
	while (!tamcorrecto) {
		cout << "Ingrese el tamano" << endl;
		tam = 0;
		cin >> tam;
		if (tam >= 5) {
			tamcorrecto = true;
		}
		else {
			cout << "El tamano debe ser mayor a 5 " << endl;
		}
	}
	arreglo1 = new int[tam];
	// empezando a desarollar la logica
	srand((unsigned)time(NULL));
	// imprimo el arreglo generado 
	for (int i = 0; i < tam; i++)
	{
		int ran = 1 + (rand() % 19);
		arreglo1[i] = ran;
		if (i == 0) {
			cout << "[" << arreglo1[i] << ",";
		}
		else if (i < tam - 1) {
			cout << arreglo1[i] << ",";
		}
		else {
			cout << arreglo1[i] << "]" << endl;
		}
	}
	// aca ordeno el arreglo 
	for (int i = 1; i < tam; ++i) {
		int temp = arreglo1[i];
		int x = i - 1;
		while (x >= 0 && arreglo1[x] > temp) {
			arreglo1[x + 1] = arreglo1[x];
			--x;
		}
		arreglo1[x + 1] = temp;
	}
	bool encontrado = false;
	bool numcorrecto = false;
	int num = 0;
	int pos; 
	int contador = 0; 

	// Validando el numero objetivo 
	while (!numcorrecto) {
		cout << "Ingrese el numero objetivo" << endl;
		num = 0;
		cin >> num;
		if (num > 0 && num < 21) {
			numcorrecto = true;
		}
		else {
			cout << "El numero debe estar entre 1 y 20" << endl;
		}
	}

	cout << "Arreglo Ordenado" << endl;
	for (int i = 0; i < tam; i++)
	{
		if (arreglo1[i] == num) {
			encontrado = true;
			pos = i;
		}
		else {
			if (num > arreglo1[i]) {
				contador++; 
			}
		}

		if (i == 0) {
			cout << "[" << arreglo1[i] << ",";
		}
		else if (i < tam - 1) {
			cout << arreglo1[i] << ",";
		}
		else {
			cout << arreglo1[i] << "]" << endl;
		}
	}
	// ultima validacion 
	if (encontrado) {
		cout << "El numero: " << num << ", se encuentra en la posicion: " << pos << ", del arreglo." << endl;
	}
	else {
		cout << "El numero: " << num << ", se deberia encontrar en la posicion: " << contador << ", del arreglo." << endl;
	}
	delete[] arreglo1;
}
int main()
{
	bool seguir = true;
	while (seguir) {
		cout << "Ingrese una opcion" << endl;
		cout << "1. Primer ejercicio" << endl;
		cout << "2. Segundo ejercicio" << endl;
		cout << "3. Salir" << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			ejercicio1();
			break;
		case 2:
			ejercicio2();
			break;
		case 3:
			seguir = false;
			break;
		default:
			cout << "Ingrese una opcion valida" << endl;
			break;
		}
	}
}

