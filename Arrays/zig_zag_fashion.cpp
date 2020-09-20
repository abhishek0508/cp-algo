// convert an array to zig-zag fashion,
// sort the array, 
// 1,2,3,6,7,8,10
// 1,3,2,7,6,10,8 -> sort and then swap adjacent elements in pair wise except first element
// time complexity -> O(n*logn)
// array is consited of disinct elements, hehcen when if we give same elements it mayn't be possible
void zig_zag(vector<int> &nums){
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(flag == true){ // < is expected
            if(nums[i]>nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
            flag=false;
        }

        else{
            if(nums[i]<nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
            flag=true;
        }
    }
}