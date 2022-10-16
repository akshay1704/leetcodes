#include<bits/stdc++.h>

using namespace std;

void convert(string& output, int start, int end){
    char stC = output[start];
    char enC = output[end];
    int length = end - start +1;
    if(stC == enC){
        for(int i=0;i<length ;i++){
            output[start+i]=stC;
        }
    }
    else if(stC == 'R' && enC == 'L'){
        for(int i=0;i<length;i++){
            output[start+i] = (i<length-i-1)?'R':(i>length-i-1)?'L':'.';
        }
    }
}


//4cases
//L...R,R...L,R...R,L...L
string pushDominoes(string dominoes){
    dominoes = 'L'+dominoes+'R';
    string temp_op = dominoes;
    for(int start=0,end =0;end<dominoes.size();end++ ){ 
            char currentC = dominoes[end];
            if(currentC != '.'){
                convert(temp_op,start,end);
                start = end;
            }
    }
    return temp_op.substr(1,dominoes.size()-1);
}

int main(){
    string dominoes = ".L.R...LR..L..";
    string op = pushDominoes(dominoes);
}