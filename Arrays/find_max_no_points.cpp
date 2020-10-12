// https://leetcode.com/problems/maximum-number-of-visible-points/
#include<bits/stdc++.h>
using namespace std;
int max_points(vector<pair<int,int>> points, int angle, vector<int> location){
    vector<pair<double,pair<int,int>>> vec;
    int res=0;
    for(int i=0;i<points.size();i++){
        vec.push_back({(points[i].second-location[1])/(points[i].first-location[0]),{points[i].first,points[i].second}});
    }
    sort(vec.begin(),vec.end(),[](pair<double,pair<int,int>> p1, pair<double,pair<int,int>> p2){
        if(p1.first > p2.first){
            return 1;
        }
        return 0;
    });

    for(int i=0;i<points.size();i++){
        cout<<vec[i].first<<" ";
    }
    return 10;
}
int main(){
    vector<pair<int,int>> points{{}};
    cout<<max_points(points,4.56,{});
    return 0;
}