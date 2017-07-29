/*
Proszę zaimplementować funkcję:
int SumBetween(int T[], int from, int to, int n);
Zadaniem tej funkcji jest obliczyć sumę liczb z n elementowej tablicy T, które w posortowanej
tablicy znajdywałyby się na pozycjach o indeksach od from do to (włącznie). Można przyjąć, że
liczby w tablicy T są parami różne (ale nie można przyjmować żadnego innego rozkładu danych).
Zaimplementowana funkcja powinna być możliwie jak najszybsza. Proszę oszacować jej złożoność
czasową (oraz bardzo krótko uzasadnić to oszacowanie).*/


#include <iostream>

using namespace std;

int parition(int *arr, int l, int r, int ind) {
	int pivot = arr[ind];
	swap(arr[ind], arr[r]);
	int l_c = l;
	for (int i = l; i < r; i++) {
		if (arr[i] < pivot) {
			swap(arr[l_c], arr[i]);
			l_c++;
		}
	}
	swap(arr[r], arr[l_c]);
	return l_c;
}

int select(int *arr, int l, int r, int k) {
	if (l == r) return arr[l];
	int ind = parition(arr, l, r, (l + r) / 2);
	if (k == ind) return arr[k];
	if (k < ind) {
		return select(arr, l, ind - 1, k);
	}
	return select(arr, ind + 1, r, k);
}

int SumBetween(int *arr, int from,int to,int n) {
	int l = select(arr, 0, n - 1, from);
	int r = select(arr, 0, n - 1, to);
	cout << "l = " << l << " r= " << r << endl;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		if (arr[i] >= l && arr[i] <= r) {
			sum += arr[i];
		}
	}
	cout << endl;
	return sum;
}

void _select() {
	int size = 13;
	int arr[] = { 5,3,2,4,1,0,8,9,6,7,10,12,11 };
	cout << SumBetween(arr, 5, 7, size);
}

int main() {
	_select();
	getchar();
	return 0;
}