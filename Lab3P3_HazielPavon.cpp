#include <iostream>
using namespace std;
void ejercicio1() {
    int* arreglo1 = nullptr;
    bool tamcorrecto = false;
    int tam = 0;

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
    int contador = 0;
    int* arreglo2 = NULL; 
    arreglo2 = new int[tam]; 
    for (int i = 0; i < tam; i++) {
        if (arreglo1[i] != 7) {
            arreglo2[contador] = arreglo1[i];
            contador++;
        }
    }
    while (contador < tam) {
        arreglo2[contador] = 7;
        contador++;
    }
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo2[i] << endl; 
    }


    delete[] arreglo1;
    delete[] arreglo2;
}
void ejercicio2() {

}
int main()
{
	bool seguir = true;
	while (seguir) {
		cout << "Ingrese una opcion" << endl;
		cout << "1. Primer ejercicio" << endl;
		cout << "2. Segunfo ejercicio" << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			ejercicio1();
			break;
		case 2:

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

