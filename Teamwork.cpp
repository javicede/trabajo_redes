#include <iostream>
#include <cstdlib>
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

int main()
{

	return 0;
}
