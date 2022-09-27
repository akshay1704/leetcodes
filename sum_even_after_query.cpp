#include <bits/stdc++.h>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int initial_sum = 0;
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                initial_sum += nums[i];
            }
        }
        for(int i=0;i<queries.size();i++){
            vector<int> val_index = queries[i];
            int old_value = nums[val_index[1]];
            nums[val_index[1]] += val_index[0];
            bool is_even = (val_index[0]%2 ==0);
            if(old_value % 2 ==0){
                if (is_even){
                    initial_sum += val_index[0];
                }
                else{
                    initial_sum -= old_value;
                }

            }
            else{
                if (!is_even){
                    initial_sum += nums[val_index[1]];
                }
            }
            answer.push_back(initial_sum);
        }
        return answer;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    vector<int> ans = sumEvenAfterQueries(nums,queries);
    string s= "abcde";
}