#include<bits/stdc++.h>

using namespace std;


vector<int> op;

int find_minima(int A[],int i,int j,int size){

    if(size==1){return -INT_MAX;}

    int idx1= i+ size/3;
    int idx2= (i+ size/3)*2;

    if(A[idx1]<A[idx1-1] && A[idx1]<A[idx1+1]){
        return A[idx1];
    }
    if(A[idx2]<A[idx2-1] && A[idx2]<A[idx2+1]){
        return A[idx2];
    }
    if(A[idx1-1]<A[idx1]){
        return find_minima(A,i,idx1-1,idx1-i);
    }
    else if(A[idx2+1]<A[idx2]){
        return find_minima(A,idx1,idx2-1,idx2-idx1);
    }
    else{
        return find_minima(A,idx2,j,j-idx2+1);
    }
    
    
}


int main(){ 
    int A[] = {INT_MAX,7,4,5,6,7,10,11,INT_MAX};
    int s = sizeof(A)/sizeof(A[0]);
    int X = find_minima(A,0,s-1,s);
    if(X != -INT_MAX){
            cout<<X;
    }

}