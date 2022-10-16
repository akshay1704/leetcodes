#include<bits/stdc++.h>

using namespace std;


char get_parent(char u, map<char,char> map){
        if(map[u] == u){return u;}
        return get_parent(map[u],map);
    }
    
bool equationsPossible(vector<string>& equations) {
        map<char,char> parent;
        vector<int> equal;
        vector<int> not_equal;
        
        for(int i=0;i<equations.size();i++){
            parent[equations[i][0]] = equations[i][0];
            parent[equations[i][3]] = equations[i][3];
            if(equations[i][1] == '='){
                equal.push_back(i);
            }
            else{
                not_equal.push_back(i);
            }
            
            for(int idx : equal){
                char u = equations[idx][0];
                char v = equations[idx][3];
                parent[get_parent(u,parent)] = parent[get_parent(v,parent)];
            }
            
            for(int idx : not_equal){
                char u = equations[idx][0];
                char v = equations[idx][3];
                if(parent[get_parent(u,parent)] == parent[get_parent(v,parent)]){
                    return false;
                }
            }
            vector<int> size()
        }
        return true;
    }


#include<string.h>

class Solution {
public:
    
    bool equationsPossible(vector<string>& equations) {
    int SIZE = 26;
    vector<vector<int>> graph(26);
    vector<int> visited(26,-1);
        for(string equation : equations){
            if(equation[1] == '=')
            {
                graph[equation[0]-'a'].push_back(equation[3] - 'a');
                graph[equation[3]-'a'].push_back(equation[0] - 'a');
            }
        }
        
        function<void(int,int)> dfs=[&](int u,int tag){
        for(int nei : graph[u]){
            if(visited[nei] == -1){
                visited[nei] = tag;
                dfs(nei,tag);
                }
            }
        };
    
        
        int tag = 0;
        for(int i=0;i<graph.size();i++){
            if(visited[i] == -1){
                tag++;
                visited[i] = tag;
                dfs(i,tag);
            }
        }
        
        for(string equation : equations){
            if(equation[1] == '!'){
                if(visited[equation[0]-'a'] == visited[equation[3]-'a']){
                    return false;
                }
            }
        }        
    return true;
    }
};