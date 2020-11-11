

int helper(int pos, vector<int> nums, int curr_or, int target){
    if(pos>=nums.size()){
        return 0;
    }

    if(curr_or == target){
        return 1;
    }

    if(dp[pos][curr_or]!=-1){
        return dp[pos][curr_or];
    }

    int ans1 = INT_MAX, ans2 = INT_MAX;

    ans1 = min(ans1,helper(pos+1,nums,curr_or,target));
    ans2 = min(ans2,1+helper(pos+1,nums,curr_or|nums[pos],target));

    dp[pos][curr_or] = min(ans1,ans2);
    return dp[pos][curr_or];
}   
vector<int> fun(vector<int> nums){
    int target_or = nums[0];
    for(int i=1;i<nums.size();i++){
        target_or = target_or | nums[i];
    }

    return helper(0,nums,0,target);
}