import java.util.*;


//Proszę zaimplementować funkcję Node* fixSortedList( Node* L ), która otrzymuje na
//wejściu listę jednokierunkową bez wartowanika. Lista ta jest prawie posortowana w tym sensie, że
//powstała z listy posortowanej przez zmianę jednego losowo wybranego elementu na losową
//wartość. Funkcja powinna przepiąć elementy listy tak, by lista stała się posortowana i zwrócić
//wskaźnik do głowy tej listy. Można założyć, że wszystkie liczby na liście są różne i że lista ma co
//najmniej dwa elementy

class node{
	public node next;
	int val;
}

public class BrokenList {
	public static void print_list(node list) {
		node list_c=list;
		while(list_c!=null) {
			System.out.println(list_c.val);
			list_c=list_c.next;
		}
	}
	
	public static void prep_and_fix(int n) {
		int [] arr = new int[n];
		for(int i=0;i<n;i++) arr[i]=i+1;
		//swap
		int ind = n/2, ind2=ind+1;
		int tmp = arr[ind];
		arr[ind]=arr[ind2];
		arr[ind2]=tmp;
		System.out.print("Swapping " + arr[ind] + " with " + arr[ind2]+"\n");
		
		//filling
		int i=0;
		node first=new node();
		first.val=arr[i];
		node first_c=first;
		for(i=1;i<n;i++) {
			node second =new node();
			first.next=second;
			second.val=arr[i];
			second.next=null;
			first=first.next;
		}
		//erase
		node removed;
		if(first_c.val>first_c.next.val) {
			removed=first_c;
			first_c=first_c.next;
			removed.next=null;
		}
		else {
			node back=first_c, current=first_c.next;
			while(current.next!=null && current.val<current.next.val) {
				back=current;
				current=current.next;
			}
			back.next=back.next.next;
			removed=current;
			removed.next=null;
		}
		System.out.print("Erased: \n");
		print_list(first_c);
		//insert
		if(first_c.val>removed.val) {
			removed.next=first_c;
			first_c=removed;
		}
		else {
			node current=first_c;
			while(current.next!=null && current.next.val<removed.val) {
				current=current.next;
			}
			node tmp_n = current.next;
			current.next=removed;
			removed.next=tmp_n;
			
		}
		//print
		System.out.print("Final: \n");
		print_list(first_c);
	}
	
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		int n = S.nextInt();
		prep_and_fix(n);
		S.close();
	}
}
