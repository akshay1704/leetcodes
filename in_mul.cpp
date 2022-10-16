#include<bits/stdc++.h>

using namespace std;

vector<int> pol_mul(vector<int> a, vector<int> b, int m, int n){
    vector<int> out(m+n-1); 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            out[i+j] += a[i]*b[j];
        }
    }
    return out;
}

string mul(string A, string B){
    vector<int> a,b;
    int index = A.size();
    for(int i=1;i<=(A.size()/3 +1);i++){
        int temp = A.size()-(3*i);

        string numstr = A.substr(max(0,temp),3);
        index -= 3;
        if(index < 0){
            numstr = A.substr(0,index+3);
        }
        int num = stoi(numstr);
        a.push_back(num);
    }
    index = B.size();
    for(int i=1;i<=(B.size()/3 +1);i++){
        int temp = B.size()-(3*i);
        
        string numstr = B.substr(max(0,temp),3);
        index -= 3;
        if(index < 0){
            numstr = B.substr(0,index+3);
        }
        int num = stoi(numstr);
        b.push_back(num);
    }

    int m= a.size();
    int n= b.size();
    vector<int> out;
    out = pol_mul(a,b,m,n);

    int carry =0;
    for(int i=0;i<out.size();i++){
        out[i] += carry;
        carry = out[i]/1000;
        out[i] = out[i]%1000;
    }

    string op ="";
    for(int i=out.size()-1;i>=0;i--){
        op += to_string(out[i]);
    }

    return op;
}


int main(){
    string A = "3617140103";
    string B = "3106136492";
    string out = mul(A,B);
}