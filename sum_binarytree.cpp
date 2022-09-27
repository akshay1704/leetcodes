#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<int> path;
    vector<vector<int>> total_path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,path,0,targetSum);
        return total_path;
    }
    
    void dfs(TreeNode* root,vector<int> path,int sum, int targetSum){
        if(root == NULL){
            return;
        }
        sum += root->val;
        //cout<<sum<<endl;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right ==NULL){
            if(sum == targetSum){
                total_path.push_back(path);
            }            
        }
        if(root->left!= NULL){
            dfs(root->left,path,sum,targetSum);
        }
        if(root->right!= NULL){
            dfs(root->right,path,sum,targetSum);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        queue<int> Q;
        dfs(root,0,Q, targetSum);
        return count;
    }
    
    void dfs(TreeNode* root, int sum,queue<int> Q, int targetSum){
        if(root == NULL){return;}
        
        Q.push(root->val);
        sum += root->val;
        cout<<sum<<endl;
        if(sum == targetSum){
            count++;
            int el = Q.front();
            sum -= el;
            Q.pop(); 
        }
        if(sum>targetSum){
            int el = Q.front();
            sum -= el;
            Q.pop();            
        }        
        if(root->left != NULL){dfs(root->left,sum,Q,targetSum);}
        if(root->right != NULL){dfs(root->right,sum,Q,targetSum);}
    }
};