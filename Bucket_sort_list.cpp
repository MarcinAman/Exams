/*
Dana jestr struktura opisująca listę jednokierunkową dla liczb rzeczywistych:
struct Node{ Node* next; double value; }
Proszę zaimplementować funkcję void Sort( Node* list ), która otrzymuje na wejściu listę
liczb rzeczywistych (z wartownikiem), wygenerowaną zgodnie z rozkładem jednostajnym na
przedziale [0,10) i sortuje jej zawartość w kolejności niemalejącej. Funkcja powinna być możliwie
jak najszybsza (biorąc pod uwagę warunki zadania). Proszę oszacować złożoność
zaimplementowanej funkcji.
*/

#include <iostream>

using namespace std;

struct node {
	node *next;
	double val;
};

void print_array(node **arr, int n) {
	cout << "Array: " << endl;
	for (int i = 0; i < n; i++) {
		node *tmp = arr[i];
		while (tmp != NULL) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

int get_len(node *list) {
	node *list_c = list;
	int sum = -1;
	while (list_c != NULL) {
		sum++;
		list_c = list_c->next;
	}
	return sum;
}

void insert(node *root, node *inserted) {
	if (root == NULL) {
		root = inserted;
	}
	else {
		node *root_c = root, *next_n = root->next;
		while (next_n != NULL && next_n->val < inserted->val) {
			root_c = next_n;
			next_n = next_n->next;
		}
		root_c->next = inserted;
		inserted->next = next_n;
	}
}

node * insertion_sort(node * first) {
	if (first->next == NULL) return first;
	node * sorted = new node;
	sorted->next = NULL;
	while (first->next != NULL) {
		node * tmp = first->next;
		first->next = tmp->next;
		tmp->next = NULL;
		insert(sorted, tmp);
	}
	insert(sorted, first);
	sorted = sorted->next;
	//delete first;
	return sorted;
}

node *bucket_sort(node *list) {
	int n = get_len(list);
	node **arr = new node*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = NULL;
	}
	list = list->next;
	while (list != NULL) {
		int ind = (int)list->val*10/n;
		if (arr[ind] == NULL) {
			arr[ind] = list;
			list = list->next;
			arr[ind]->next = NULL;
		}
		else {
			node *tmp = arr[ind];
			arr[ind] = list;
			list = list->next;
			arr[ind]->next = tmp;
		}
	}
	//print_array(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] != NULL) {
			arr[i] = insertion_sort(arr[i]);
		}
	}
	//print_array(arr, n);
	node *first = new node, *current = first;
	for (int i = 0; i < n; i++) {
		if (arr[i] != NULL) {
			current->next = arr[i];
			while (current->next != NULL) current = current->next;
		}
	}
	return first;
}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void _bucket_sort(int n) {
	cout << "Before: " << endl;
	node *begining = new node;
	node *second = new node, *current;
	second->val = fRand(0, 10);
	cout << second->val << " ";
	begining->next = second;
	while (n--) {
		current = new node;
		current->val = fRand(0, 10);
		cout << current->val << " ";
		second->next = current;
		second = current;
	}
	second->next = NULL;
	cout << endl;
	node *sorted_list = bucket_sort(begining);
	sorted_list = sorted_list->next;
	cout << "After: " << endl;
	while (sorted_list != NULL) {
		cout << sorted_list->val << " ";
		sorted_list = sorted_list->next;
	}
	cout << endl;
}

int main() {
	_bucket_sort(10);
	getchar();
	return 0;
}