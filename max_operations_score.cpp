#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int get_score(int left, int steps, int n, vector<int> &nums, vector<int> &M){
        if(steps == M.size()){
            return 0;
        }
        if(dp[left][steps]!=INT_MIN){ return dp[left][steps];}

        int left1 = nums[left]*M[steps] + get_score(left+1,steps+1,n,nums,M);
        int right1 = nums[n-1-steps-left] + get_score(left,steps+1,n,nums,M);

        return dp[left][steps] = max(left1,right1);
    }

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m= multipliers.size();
    dp.resize(m+1,vector<int>(m+1,INT_MIN));
    return get_score(0,0,n,nums,multipliers);

    }





int main(){
    vector<int> nums = {-5,-3,-3,-2,7,1};
    vector<int> multipliers = {-10,-5,3,4,6};
    int res = maximumScore (nums,multipliers);
}
