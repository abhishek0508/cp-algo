// easy solution ->
// since order of flips doesn't matter,
// and count of flips are odd, then its matter otherwise no,

// simple solution would be greedily flip the bits for every 0,
// and return count

// time complexity for below solution -> O(n*k)
int min_flips(vector<int> nums, int k){
    int count=0;
    for(int i=0;i<nums.size()-k;i++){
        if(nums[i]==0){
            count++;
            for(int j=i;j<i+k;j++){
                nums[j]=1-nums[j];
            }
        }
    }

    for(int i=nums.size()-k;i<nums.size();i++){
        if(nums[i]==0){
            return -1;
        }
    }
    return count;
}

// time complexity for below solution -> O(N),space O(N)
int min_flips(vector<int> nums, int k){
    int count=0;
    queue<int> record;
    int pivot;
    for(int i=0;i<nums.size()-k;i++){
        if(record.size()%2==0){
            pivot = nums[i];
        }
        else
            pivot = 1-nums[i];

        if(pivot == 0){
            count++;
            record.push(i+k-1);
        }
        if(!record.empty() && i == record.top()){
            record.pop();
        }
    }

    if(record.empty()){
        return ans;
    }
    return -1;
}