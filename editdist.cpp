#include<bits/stdc++.h>
using namespace std;



int minMutation(string startGene, string endGene, vector<string>& bank) {
    queue<string> q;
    map<string,int> visited;

    int steps = 0;
    q.push(startGene);
    visited[startGene] = 1;
    string temp = "ACGT";

    while(!q.empty()){
        int n = q.size();
        for(int i=q.size();i>0;i--){
            string str = q.front();
            q.pop();

            if(str == endGene){return steps;}
            for(int j =0;j<8;j++){
                char c = str[j];
                for(int k=0;k<4;k++){
                    str[j] = temp[k];
                    if(visited[str]==0 && find(bank.begin(),bank.end(),str)!=bank.end()){
                        q.push(str);
                        visited[str] = 1;
                    }
                }
                str[j] = c;
            }
            
        }
        steps++;
    }

    return -1;
}


int main(){
    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    int res = minMutation(startGene,endGene,bank);
    cout<<'q';
}