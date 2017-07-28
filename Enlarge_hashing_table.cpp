#include <iostream>

using namespace std;
/*
Tablica korzysta z funkcji haszującej int hash(int x) i liniowego rozwiązywania konfliktów (ujemne wartości w tablicy table oznaczają wolne pola).

Doskonałością takiej tablicy nazywamy liczbę elementów x takich, że pozycja x w tablicy to hash(x) % size (a więc x jest na "swojej" pozycji).

Proszę napisać funkcję void enlarge(HT* ht), która powiększa tablicę dwukrotnie i wpisuje elementy w takiej kolejności, by doskonałość powstałej tablicy była największa. Funkcja powinna być możliwie najszybsza.

*/

struct HT {
	int *arr;
	int n;
};

int hash_f(int a) {
	return a;
}

void make_bigger(HT *ht) {
	int m = 2 * (ht->n);
	int *newHT = new int[m];
	for (int i = 0; i < m; i++) newHT[i] = -1;
	for (int i = 0; i < ht->n; i++) {
		if (ht->arr[i] != -1) {
			int ind = hash_f(ht->arr[i]) % m;
			if (newHT[ind] == -1) {
				newHT[ind] = ht->arr[i];
				ht->arr[i] = -1;
			}
		}
	}
	for (int i = 0; i < ht->n; i++) {
		if (ht->arr[i] != -1) {
			int ind = hash_f(ht->arr[i]) % m;
			while (newHT[i] != -1) {
				ind++;
				ind = ind%m;
			}
			newHT[ind] = ht->arr[i];
			ht->arr[i] = -1;
		}
	}
	int *tmp = ht->arr;
	ht->arr = newHT;
	//delete(tmp);
	ht->n = m;
}

void _enlarge() {
	int size = 5;
	int arr[] = { 1,3,2,4,5 };
	HT *A = new HT;
	A->arr = arr;
	A->n = size;
	make_bigger(A);
	for (int i = 0; i < A->n; i++) {
		cout << A->arr[i] << " ";
	}
}

int main() {
	_enlarge();
	getchar();
	return 0;
}