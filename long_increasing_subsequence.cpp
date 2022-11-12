#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> A;
vector<int> B;
vector<int> C;

int findLong(int i, int j,vector<int> A, vector<int> B){
    if(i==0 || j ==0){
        
        return 0;
    }
    if(dp[i][j] != 0){return dp[i][j];}

    if(A[i] == B[j]){
        return 1+findLong(i-1,j-1,A,B);
    }
    else{
        return max(findLong(i-1,j,A,B),findLong(i,j-1,A,B));
    }
    return 0;
}

int main(){

    vector<int> A = {30, 60, 20, 25, 75, 40, 10, 50, 90, 70, 80,100,20,140};
    int m = A.size();
    vector<int> B;
    for(int i=0;i<m;i++){
        if(find(B.begin(),B.end(),A[i])==B.end()){
            B.push_back(A[i]);
        }
    }
    sort(B.begin(),B.end());
    int n = B.size();
    dp.resize(m+1,vector<int>(n+1,0));

    int res = findLong(m-1,n-1,A,B);
    cout<<res;

}