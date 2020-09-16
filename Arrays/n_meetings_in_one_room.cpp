// find the maximum no of meeting that can be accomodated in a single room

int nmeeting(vector<pair<int,int>> meetings){
    sort(meetings.begin(),meetings.end(),[](pair<int,int> p1, pair<int,int> p2){
        if(p1.second>p2.second)
            return 1;
        return 0;
    })

    int count=1;
    int time_end = meetings[0].second;
    for(int i=1;i<meetings.size();i++){
        if(meetings[i].first > time_end){
            time_end = meetings[i].second;
            count++;
        }
    }
    return count;
}