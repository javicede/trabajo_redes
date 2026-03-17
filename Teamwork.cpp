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
	for (int i = 0; cadena[i] != '\0'; i++)
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
	if (suma > final) {
		cout << "El valor de la suma final es: " << suma << endl;
	}
	else {
		cout << "Fallo en la suma." << endl;
		delete[] ID; // se elimina el vector para ahorrar memoria. Se usa cuando utilizas 'new'.
		exit(0);
	}
	delete[] ID; // caso donde sí se cumple, se sigue borrando para ahorrar memoria después de haber hecho el procedimiento
}

int main()
{

	return 0;
}
