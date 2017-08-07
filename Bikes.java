/*W ramach obchodów międzynarodowego święta cyklistów organizatorzy przewidzieli górską
wycieczkę rowerową. Będzie się ona odbywać po bardzo wąskiej ścieżce, na której rowery mogą
jechać tylko jeden za drugim. W ramach zapewnienia bezpieczeństwa każdy rowerzysta będzie
miał numer identyfikacyjny oraz małe urządzenie, przez które będzie mógł przekazać
identyfikator rowerzysty przed nim (lub -1 jeśli nie widzi przed sobą nikogo). Należy napisać
funkcję, która na wejściu otrzymuje informacje wysłane przez rowerzystów i oblicza rozmiar
najmniejszej grupy (organizatorzy obawiają się, że na małe grupy mogłyby napadać dzikie
zwierzęta). Dane są następujące struktury danych:
struct Cyclist {
int id, n id; // identyfikator rowerzysty oraz tego, którego widzi
};
Funkcja powinna mieć prototyp int smallestGroup( Cyclist cyclist[], int n ), gdzie
cyclist to tablica n rowerzystów. Funkcja powinna być możliwie jak najszybsza. Można założyć,
że identyfikatory rowerzystów to liczby z zakresu 0 do 108
(osiem cyfr napisanych w dwóch
rzędach na koszulce rowerzysty) i że pamięć nie jest ograniczona. Rowerzystów jest jednak dużo
mniej niż identyfikatorów (nie bez powodu boją się dzikich zwierząt). Należy zaimplementować
wszystkie potrzebne struktury danych.
*/


import java.util.*;

class Cyclists{
	int id,n_id;
}

class Set{
	int ind_f,count;
}

class smallestGroup{
	Cyclists [] cyclists;
	int n,last;
	private Set [] set;
	
	int find_next(int ind) {
		if(ind==-1) return 0;
		for(int i=0;i<n;i++) {
			if(cyclists[i].n_id==ind) {
				return 1+find_next(cyclists[i].id);
			}
		}
		return 0;
	}
	
	
	void fill() {
		set=new Set[n];
		last=0;
		for(int i=0;i<n;i++) {
			Set tmp = new Set();
			set[i]=tmp;
			set[i].count=0;
			set[i].ind_f=-1;
		}
		for(int i=0;i<n;i++) {
			if(cyclists[i].n_id==-1) {
				set[last].ind_f=cyclists[i].id;
				set[last].count=1;
				last++;
			}
		}
		for(int i=0;i<n;i++) {
			if(set[i].ind_f!=-1) {
				set[i].count+=find_next(set[i].ind_f);
			}
			else {
				break;
			}
		}
	}
	void print_min() {
		int min=n,ind=0;
		while(set[ind].ind_f!=-1) {
			if(set[ind].count<min) min=set[ind].count;
			ind++;
		}
		System.out.println(min);
	}
	void print_set() {
		int ind=0;
		while(set[ind].ind_f!=-1) {
			System.out.println(set[ind].ind_f+" "+set[ind].count);
			ind++;
		}
	}
}

public class Bikes {
	public static void main(String[] args) {
		smallestGroup A = new smallestGroup();
		A.n=7;
		A.cyclists=new Cyclists[A.n];
		for(int i=0;i<A.n;i++) {
			Cyclists tmp = new Cyclists();
			A.cyclists[i]=tmp;
		}
		A.cyclists[0].id=1;A.cyclists[0].n_id=2;
		A.cyclists[1].id=4;A.cyclists[1].n_id=5;
		A.cyclists[2].id=6;A.cyclists[2].n_id=3;
		A.cyclists[3].id=2;A.cyclists[3].n_id=-1;
		A.cyclists[4].id=3;A.cyclists[4].n_id=1;
		A.cyclists[5].id=9;A.cyclists[5].n_id=7;
		A.cyclists[6].id=7;A.cyclists[6].n_id=-1;
		A.fill();
		A.print_min();
		A.print_set();
	}

}
