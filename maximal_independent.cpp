#include<bits/stdc++.h>

using namespace std;

vector<int> parent = {INT_MIN,-1,1,1,1,2,2,2,3,4,4,6};
vector<int> weights = {0,15,8,16,18,3,5,5,7,2,9,4};

int size = 10;
vector<int> dp(12,-1);

class node 
{ 
    public:
    int data; 
    int index;
    vector<node*> children; 
    node* parent;
}; 

map<int,node*> mp;

node* newNode(int data) 
{ 
    node* temp = new node(); 
    temp->data = data;
    return temp; 
} 


int MIS(node* root){
    if(root==NULL){
        return 0;
    }
    if(dp[root->index]!=-1){
        return dp[root->index];
    }
    if(root->children.empty()){
        return root->data;
    }
    int liss_ex = 0;
    int liss = root->data;
    vector<node*> tmp = root->children;

    while(!tmp.empty()){
        node* nd = tmp.back();
        liss_ex += MIS(nd);
        vector<node*> tmp2 = nd->children;
        while(!tmp2.empty()){
            node* nd2 = tmp2.back();
            liss += MIS(nd2);
            tmp2.pop_back();
        }
        tmp.pop_back();
    }

    return max(liss,liss_ex);

}

int main(){
    int m = weights.size();

    node* root;
    for(int i=1;i<m;i++){
        node* t1 = newNode(weights[i]);
        t1->index = i;
        if(mp.find(i)==mp.end()){
            mp[i] = t1;
        }       
        t1->parent = mp[parent[i]];
        if(parent[i] != -1){
            node* prt = mp[parent[i]];
            prt->children.push_back(t1);
        }
        else{
            root = t1;
        }

    }

    int res = MIS(root);
    cout<<res;

}