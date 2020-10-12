// partition equal subset sum
// exactly same as few number of coins, 
// only here is that we can't use same coin twice, 
// hence right to left computation

#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
    }
    
    if(sum%2!=0){
        return false;
    }
    
    bool dp[sum/2+1];
    // sort(nums.begin(),nums.end());
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    for(int i=0;i<nums.size();i++){
        for(int j=sum/2;j>=1;j--){
            if(j>=nums[i]){
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
    }
    
    return dp[sum/2];
}