// given an array in which "m" no of operations can be done,
// in each operation you can increase the subarray of size k by 1
// now using these "m" no of operations maximize the minimum element in array

int fun(vector<int> nums, int n, int m){
    // every subarrays of size k find the maximum element
    // now put the maximum element along with its left & right index
    // 
    // create a priority_qeuee with those elements, and then push all those elements
    // into the queue
    // pop element and increases the left * right index, again push into priority qeuee
    // for m no of times, 
    // finally do the cumulative sum 
    // find the minimum element in cumulative sum
    // 
    // 
    deqeue<pair<int,pair<int,int>>> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    priority_queue<pair<int,pair<int,int>>> pq;

    return x;
}