#include <bits/stdc++.h>

using namespace std;

int max_subarray(int n1[], int n2[] , int m, int n){

    int dp[m+1][n+1];
    for(int i = 0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] =0;
        }
    }

    for(int i = 1;i<=m+1;i++){
        for(int j=1;j<= n+1;j++){
            if(n1[i-1] == n2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }

    int max = 0;
    for(int i = 0;i<=m;i++){
        for(int j=0;j<= n;j++){
            if(dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }

    return max;
}

int main(){
    int nums1[] = {1,2,3,2,1};
    int nums2[] ={3,2,1,2,7};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    int length = max_subarray(nums1,nums2,m,n);

}