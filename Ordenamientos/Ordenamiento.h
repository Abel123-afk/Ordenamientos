#pragma once
#include<ctime>
using namespace std;

typedef unsigned long long ull;
template<class T>
class Ordenamiento
{
private:
	double timeMerge;
	double timeQuickSort;
	void _swap(T* a, T* b) {
		T aux = *a;
		*a = *b;
		*b = aux;
	}
	void merge(T* iz, T*der, T* numeros, ull n)
	{
		int i, j, k;
		i = j = k = 0;
		while (i < n / 2 && j < n - n / 2)
		{
			if (iz[i] < der[j]) {
				numeros[k] = iz[i];
				i++;
				k++;
			}
			else {
				numeros[k] = der[j];
				j++;
				k++;
			}
		}
		while (i < n / 2)
		{
			numeros[k] = iz[i];
			i++;
			k++;
		}
		while (j < n - n / 2)
		{
			numeros[k] = der[j];
			j++;
			k++;
		}
	}

	ull partition(T* A, ull p, ull r) {
		T x = A[r]; //el pivote
		ull i = p - 1; //indice de los menores
		for (ull j = p; j < r; j++) {
			if (A[j] <= x) {
				i++;
				_swap(&A[i], &A[j]);
			}
		}
		_swap(&A[i + 1], &A[r]);
		return i + 1;
	}
	ull sortQuick(T* arr, ull i, ull d, ull p) {
		while (!(d == p && i == p && d == i)) {
			while (arr[d] >= arr[p] && i < d) {
				--d;
			}
			_swap(&arr[d], &arr[p]);
			p = d;
			while (arr[p] >= arr[i] && i < d) {
				++i;
			}
			_swap(&arr[p], &arr[i]);
			p = i;
		}
		return p;
	}
public:
	Ordenamiento() {
		timeMerge = 0;
		timeQuickSort = 0;
	}
	~Ordenamiento() {}
	T quickSelect(T* A, ull p, ull r, ull k) {
		if (p == r) return A[p];
		//indice del pivote con A ordenado Izq(Menores) Der(Mayores) al pivote
		ull q = partition(A, p, r);
		ull l = q - p + 1; //nro elementos del sub arreglo donde se encuentra el kesimo elemento
		if (k == l)
			return A[q];
		else if (k < l) {
			return quickSelect(A, p, q - 1, k);
		}
		else {
			return quickSelect(A, p, q, k - l);
		}
	}
	void MergeSort(T* A, int n)
	{
		clock_t inicio = clock();
		if (n > 1)
		{
			T* izq = new T[n / 2];
			T* der = new T[n - n / 2];
			for (int i = 0; i < n / 2; i++)
			{
				izq[i] = A[i];
			}
			for (int j = n / 2; j < n; j++)
			{
				der[j - n / 2] = A[j];
			}
			MergeSort(izq, n / 2);
			MergeSort(der, n - n / 2);
			merge(izq, der, A, n);
		}
		clock_t fin = clock();
		timeMerge = (fin - inicio) / CLOCKS_PER_SEC;
	}
	void quickSort(T*arr,ull i, ull d, ull p) {
		if (d <= i) { return; }
		ull index = sortQuick(arr,i, d, p);
		quicksort(i, index, p);
		quicksort(index + 1, d, index + 1);
	}
	double getTimeMerge()
	{
		return timeMerge;
	}
	double getTimeQuickSelect()
	{
		return timeQuickSelect;
	}
	void print(T *arr, ull n) {
		for (size_t i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
