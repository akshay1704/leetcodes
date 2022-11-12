#include<bits/stdc++.h>

using namespace std;

struct return_type{ 
        vector<long long int> X;
        long long int count;
};

return_type merge_and_sort(return_type B, return_type C, int half_size_1, int half_size_2){
    int i=0;
    int j=0;
    return_type result;
    result.X = {};
    result.count = 0;
    long long int count = 0;
    while(i<half_size_1 or j<half_size_2){
        if(j>=half_size_2 || (i<half_size_1 && B.X[i]<=C.X[j])){
            result.X.push_back(B.X[i]);
            count += j;
            i++;
        }
        else{
            result.X.push_back(C.X[j]);
            j++;
        }
    }
    result.count = count;
    return result;
}

return_type sort_and_count(vector<long long int> A, int n){

    if(n==1){
        return_type ret;
        ret.X = A;
        ret.count = 0;
        return ret;
    }

    int half_size_1 = floor(n/2);
    int half_size_2 = n-half_size_1;
    vector<long long int> half_1 = {A.begin(),A.begin()+half_size_1};
    vector<long long int> half_2 = {A.begin()+half_size_1,A.end()};

    return_type B = sort_and_count(half_1,half_size_1);
    return_type C = sort_and_count(half_2,half_size_2);

    return_type res = merge_and_sort(B,C,half_size_1,half_size_2);
    res.count += B.count;
    res.count += C.count;
    return res;
}

int main(){
    long long int size;
    cin>>size;
    long long int X[size];
    int n = sizeof(X) / sizeof(X[0]);

    for(long long int i=0;i<size;i++){
        long long int x;
        cin>>x;
        X[i] = x;
    }
    vector<long long int> A = {X,X+n};
    return_type result = sort_and_count(A,size);
    cout<<result.count<<endl;


    // int size = 0;
    // long long int out;
    // ifstream f;
    // ifstream f2;
    // vector<string> infiles = {"input1.txt","input2.txt","input3.txt","input4.txt","input5.txt"};
    // vector<string> outfiles = {"output1.txt","output2.txt","output3.txt","output4.txt","output5.txt",};
    // for(int f1 = 0; f1<5;f1++){
    //     vector<long long int> A = {};
    //     string file_name = "Data/"+infiles[f1];
    //     f.open(file_name);
    //     bool x = f.is_open();
    //     string line;
    //     getline(f,line);
    //     size = stoi(line);
    //     int i=0;
    //     while(f && i<size){
    //             long long int x;
    //             getline(f,line);
    //             x = stoi(line);
    //             A.push_back(x);
    //             i++;
    //         }
    //     f.close();
    //     file_name = "Data/"+ outfiles[f1];
    //     f2.open(file_name);
    //     x = f2.is_open();
    //     getline(f2,line);
    //     out = stoll(line);
    //     return_type result = sort_and_count(A,size);
    //     cout<<"Calculated Result : "<<result.count<<endl;
    //     cout<<"Actual Result : "<<out<<endl;
        
    //     cout<<(result.count==out?"True":"False");
    //     cout<<endl;
    //     f2.close();
    //    }
}