//http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/

#include <iostream>

using namespace std;

int minOf3(int a, int b, int c){
    return min(min(a,b),c);
}

//Function used to test the arr

void print(int **arr, int m, int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int editDistance(string a, string b, int n, int m){
    int **arr = new int*[m+1];
    for(int i=0;i<m+1;i++){
        arr[i]=new int[n+1];
    }
    //empty strings
    for(int i=0;i<=m;i++){
        arr[i][0]=i;
    }
    for(int i=0;i<=n;i++){
        arr[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[j-1]==b[i-1]){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=1+minOf3(arr[i][j-1],arr[i-1][j],arr[i-1][j-1]);
            }
        }
    }
    //print(arr,m,n);
    return arr[m][n];
}

int main(){
    string a = "sunday";
    string b = "saturday";
    cout << editDistance(a,b,a.length(),b.length()) << endl;
    return 0;
}
