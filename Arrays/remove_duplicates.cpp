fun(vector<int> nums,int k){
    int i=0;
    for(int x: nums){
        if(i<k || x>nums[i-k]){
            nums[i]=x;
            i++;
        }
    }
    return i;
}

// where k duplicates are allowed, and array is sorted