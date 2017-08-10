https://youtu.be/NJuKJ8sasGk
#include <iostream>

using namespace std;

int minAmount(int *A, int T, int n){
    int *cost = new int[T+1];
    for(int i=0;i<=T;i++){
        cost[i]=1000;
    }
    cost[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=T;j++){
            if(j-A[i]>=0){
                cost[j]=min(cost[j],1+cost[j-A[i]]);
            }
        }
    }

    return cost[T];
}

int minAmountWithPrinting(int *A, int T, int n){
    int *cost = new int[T+1];
    int *taken = new int[T+1];
    for(int i=0;i<=T;i++){
        taken[i]=-1;
        cost[i]=1000;
    }
    cost[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=T;j++){
            if(j-A[i]>=0){
                if(cost[j-A[i]]+1<cost[j]){
                    cost[j]=1+cost[j-A[i]];
                    taken[j]=i;
                }
            }
        }
    }
    for(int i=0;i<=T;i++){
        cout << taken[i] << " ";
    }
    cout << endl;
    return cost[T];
}

int main(){
    int a[]={7,2,3,6};
    cout << minAmountWithPrinting(a,13,4) << endl;
    return 0;

}
