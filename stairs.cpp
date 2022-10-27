#include<bits/stdc++.h>

using namespace std;

map<int,int> mp;
int recurse(int n){
        if(n<=2){
            return n;
        }
        if(mp.find(n)==mp.end()){
            mp[n] = recurse(n-1) + recurse(n-2);  
        }
         
        return mp[n];
    }
    
    int climbStairs(int n) {
        return recurse(n);
    }

int main(){
    int res = climbStairs(4);
    cout<<res;
}