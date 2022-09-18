#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height){
    stack<int> S;
    int count = 0;
    for(int i =0 ; i < height.size();i++){
        while(!(S.empty()) && height[i] > height[S.top()]){
            int base_height = height[S.top()];
            S.pop();
            if(S.empty()){
                break;
            }
            int d = i - S.top() - 1;
            int minimum_height = min(height[i],height[S.top()]) - base_height;
            count += minimum_height * d;
        }
        S.push(i);
    }
    return count;
}
    


int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height1 = {3, 0, 2, 0, 4};
    int a = trap(height1);
    return 0;
}