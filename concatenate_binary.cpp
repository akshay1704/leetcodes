#include <bits/stdc++.h>

using namespace std;

int numberofbits(int a){
    return log2(a)+1;
}

int concatenatedBinary(int n) {
    long ans = 0, MOD = 1e9 + 7;
    for (int i=1;i<=n;i++){
        int len = numberofbits(i);
        ans = ((ans << len)%MOD +i)% MOD;
    }
    return ans;
}
        
int main(){
    int n = 12;
    int result = concatenatedBinary(n);
    cout<<('a');    
}