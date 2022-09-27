 #include<bits/stdc++.h>

 using namespace std;
 
static int counts =0;
void getCount(vector<int> nums, int i, int bitOrvalue, int max){
        if (i==nums.size()){return;}
        
        if((bitOrvalue | nums[i]) == max){counts++;}
        getCount(nums,i+1,bitOrvalue,max);
        getCount(nums,i+1,bitOrvalue|nums[i],max);
    }
    
int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        for(int num : nums){
            max = max | num;
        }
        
        getCount(nums,0,0,max);
        return counts;
} 

int main(){
    vector<int> nums = {3,2,1,5};
    int c = countMaxOrSubsets(nums);
    cout<<c<<endl;
}