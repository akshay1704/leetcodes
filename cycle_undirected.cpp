#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


unordered_map<int,int> parent_map;
int visited[5] = {0};
bool cycle = false;
int cycle_start = 0;

class Graph {
    int V;
    list<int>* adj;
 
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool dfs(int u);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::dfs(int u)
{
    visited[u] = 1;
    list<int>::iterator v;
    bool flag = false;
    for(v=adj[u].begin();v!=adj[u].end();v++){
        if (*v != parent_map[u]){
            if(visited[*v] == 0){
                visited[*v] = 1;
                parent_map[*v] = u;
                flag = dfs(*v);
                if(flag){
                    return true;
            }
            }
            else{
                parent_map[*v] = u;
                cycle = true;
                cycle_start = *v;
                return true;
            }
        }       
    }
return false;   
}

int main(){
    Graph g1(7);

    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(1, 4);
    g1.addEdge(1, 3);
    g1.addEdge(2, 4);
    g1.addEdge(3, 4);
    g1.addEdge(3, 5);
    g1.addEdge(5, 4);
    g1.addEdge(6, 4);
    parent_map[0] = -1;
    if (g1.dfs(0)){
        cout<<"Cycle found - "<<endl;
        cout<<cycle_start<<"-";
        int i = parent_map[cycle_start];
        while(i!=cycle_start){
            cout<<i<<"-";
            i=parent_map[i];
        }
    }

}