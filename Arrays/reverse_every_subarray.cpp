// reverse every subarray of size k
void reverse_subarray(vector<int> &nums, int k){
    for(int i=0;i<n;i+=k){
        int l=i, r=min(i+k-1,n);
        while(l<r){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
}