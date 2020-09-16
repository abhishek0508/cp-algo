// max of all windows of size k

vector<int> fun(vector<int> nums, int k){
    deque<int> dq(k);
    vector<int> res;

    for(int i=0;i<k;i++){
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i=k;i<n;i++){

        res.push_back(nums[dq.front()]);

        // pop all out of current window
        while(!dq.empty() && dq.front()<=(i-k)){
            dq.pop_front();
        }

        // pop not useful in current window
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);
    return res;
}