// Given an array of integers out of order, determine the bounds of the 
// smallest window that must be sorted in order for the entire array to be sorted.
// For example, given [3, 7, 5, 6, 9], you should return (1, 3).
vector<int> fun(vector<int> nums){
    int s,e;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            s=i-1;
            break;
        }
    }
    for(int i=nums.size()-2;i++){
        if(nums[i]>nums[i+1]){
            e = i;
            break;
        }
    }

    int min=INT_MAX,max=INT_MIN;
    for(int i=s;i<=e;i++){
        
    }
    return {};
}   