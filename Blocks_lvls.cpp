#include <iostream>

using namespace std;

/*
Dany jest ciąg klocków (k1,...,kn).

Kolcek ki zaczyna się na pozycji ai i kończy na pozycji bi (wszytkie pozycje to liczby naturalne) oraz ma wysokość 1.

Klocki układane są po kolei. Jeśli klocek nachodzi na któryś z poprzednich, to jest mocowany na szcycie poprzedniego klocka.

Na przykład dla klocków o pozycjach (1,3), (2,5), (0,3), (8,9), (4,6) powstaje struktura o wysokości trzech klocków.

Proszę podać możliwie najszybszy algorytm, który oblicza wysokość powstałej konstrukcji (bez implementacji) oraz oszacować jego złożoność obliczeniową.

*/

struct d_int {
	int a, b;
};

int max_lvl(d_int *arr, int n) {
	int max = arr[0].b, min = arr[0].a;
	for (int i = 1; i < n; i++) {
		if (arr[i].b > max) max = arr[i].b;
		if (arr[i].a < min) min = arr[i].a;
	}
	int *arr_lvl = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++) arr_lvl[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i].a - min; j <= arr[i].b - min; j++) arr_lvl[j]++;
	}
	int max_lvl = 0;
	for (int i = 0; i < max - min + 1; i++) {
		if (max_lvl < arr_lvl[i]) max_lvl = arr_lvl[i];
	}
	delete(arr_lvl);
	return max_lvl;
}

void add(int a, int b, d_int *arr, int i) {
	arr[i].a = a;
	arr[i].b = b;
}

void _max_lvl() {
	int size = 5;
	d_int *arr=new d_int[size];
	add(1, 3, arr, 0);
	add(2,5, arr, 1);
	add(0,3, arr, 2);
	add(8,9,arr, 3);
	add(4, 6, arr, 4);
	cout << max_lvl(arr, size);
}

int main() {
	_max_lvl();
	getchar();
	return 0;
}