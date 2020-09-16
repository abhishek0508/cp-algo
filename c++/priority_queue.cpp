#include<bits/stdc++.h>
using namespace std;
int main(){
    auto cmp = [](pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
        return p1.first < p2.first;
    };

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> pq(cmp);
    
    pq.push({13,{2,4}});
    pq.push({11,{2,4}});
    pq.push({1,{2,4}});
    pq.push({23,{2,4}});
    
    while(!pq.empty()){
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    }
    
    return 0;
}