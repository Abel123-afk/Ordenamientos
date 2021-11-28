#include<iostream>
#include<conio.h>

#include"Ordenamiento.h"
using namespace std;

int main()
{
	srand(time(NULL));
	
	int n = 10;
	int* arreglo = new int[n];
	Ordenamiento<int> ord = Ordenamiento<int>();
	char t;
	do{
		cout << "Ingresa M: ";
		cin >> t;
		t = toupper(t);
		for (int i = 0; i < n; i++)
		{
			arreglo[i] = rand() % 200 + rand() % 50;
		}
		for (int i = 0; i < n; i++) {
			cout << arreglo[i] << " ";
		}
		cout << endl;
		int k = 1; //el kesimo menor elemento del arreglo
		int e = ord.quickSelect(arreglo, 0, n - 1, k);
		ord.print(arreglo, n);
		cout << "\nEl menor k-esimo elemento de (k= " << k << " ) es: " << e << '\n';
		//cout << "El kesimo elemento es: " << e << endl;
		
	} while (t == 'M');
	system("pause>=NULL");
	return 0;
}