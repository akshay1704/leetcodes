#include<bits/stdc++.h>

using namespace std;


    
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows= matrix.size();        
        int columns = matrix[0].size();
        
        vector<vector<int>> dp(rows,vector<int>(columns,0));
        int maxs = 0;
        for(int i=1;i<rows;i++){
            for(int j=1;j<columns;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
                    maxs = max(maxs,dp[i][j]);
                }
            }
        }
        return maxs*maxs;
    }

int main(){
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int x = maximalSquare(matrix);
    cout<<x;
}