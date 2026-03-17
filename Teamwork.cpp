#include <iostream>
#include <cstdlib> // para usar exit()
using namespace std;


extern "C" bool IsValidAssembly(int a, int b, int c);
void ControlUppercaseCountPattern()
{
	char cadena1[20];
	char cadena2[20];
	int mayus = 0;

	cin >> cadena1;
	for (int i = 0; cadena1[i] != '\0'; i++)
	{
		if (cadena1[i] >= 'A' && cadena1[i] <= 'Z')
			mayus++;
	}
	if (mayus != 6) {
		cout << "Intruso detectado.";
		exit(0);
	}
	cin >> cadena2;
	if (strcmp(cadena2, "5fdk4fi") != 0) {
		cout << "El acceso no fue correcto.";
		exit(0);
	}
}

void AsmAccess() {
	int a, b, c;
	cin >> a >> b >> c;
	if (IsValidAssembly(a, b, c) == 0)
	{
		cout << "Intruso detectado.";
		exit(0);
	}
}

void SumArray() {
	int tamano = 3;
	unsigned char* ID = new unsigned char[tamano]; // nos aseguramos que cada valor esté entre 0 y 255
	// Lee los valores de la terminal y se colocan en el vector
	cout << "Introduzca los tres elementos del vector (0-255): " << endl;
	for (int i = 0; i < tamano; i++) {
		int temp; // aseguramos que guarde el valor entero
		cin >> temp;
		ID[i] = (unsigned char)temp; // se guarda dicho valor dentro de los 8  bits
	}
	int suma = ID[0] + ID[1] + ID[2];
	int final = (ID[1] + 1) * 30;
	if (suma <= final) {
		cout << "Fallo en la suma." << endl;
		delete[] ID; // se elimina el vector para ahorrar memoria. Se usa cuando utilizas 'new'.
		exit(0);
	}
	delete[] ID; // caso donde sí se cumple, se sigue borrando para ahorrar memoria después de haber hecho el procedimiento
}

void ControlBitParity(unsigned char* ID) {
	unsigned int num1;
	unsigned int num2;
	cout << "Introduzca los dos números enteros sin signo: ";
	cin >> num1;
	cin >> num2;
	// Aislamos los bits que se han usado en las posiciones guardadas de ID[3] y ID[4]
	int bitA = (num1 >> ID[3]) & 0x00000001;
	int bitB = (num2 >> ID[4]) & 0x00000001;

	if (bitA != bitB){
		cout << "Entrada incorrecta." << endl;
		delete[] ID;
		exit(0);
	}
	int contador_unos1 = 0;
	// contador de 1s entre ID[3] y ID[4]
	for (int i = ID[2]; i <= ID[4]; i++) {
		if ((num1 >> i) & 1) {
			contador_unos1++;
		}
	}
	int contador_unos2 = 0;
	// contador de 1s entre ID[1] y ID[3]
	for (int i = ID[1]; i <= ID[3]; i++) {
		if ((num2 >> i) & 1) {
			contador_unos2++;
		}
	}
	// suma de ambos contadores, condición de que NO se cumpla
	if ((contador_unos1 + contador_unos2) % 2 != 0) {
		cout << "Fallo" << endl;
		delete[] ID;
		exit(0);
	}
	delete[] ID;
}

int main()
{

	return 0;
}
