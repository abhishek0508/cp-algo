// find maxm activity that a persion can do
int activity_count(vector<pair<int,int>> activities){
    sort(activities.begin(),activities.end(),[](pair<int,int> p1, pair<int,int> p2){
        if(p1.second>p2.second)
            return 1;
        return 0;
    })

    int count=1;
    int time_end = activities[0].second;
    for(int i=1;i<activities.size();i++){
        if(activities[i].first > time_end){
            time_end = activities[i].second;
            count++;
        }
    }
    return count;
}