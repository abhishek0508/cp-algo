// given an array find the largest number formed from the array
#include<bits/stdc++.h>
using namespace std;
void largest_number(vector<int> &nums){
    sort(nums.begin(),nums.end(),[](int x, int y){
        string num1 = to_string(x);
        string num2 = to_string(y);
        if(num1.append(num2)<num2.append(num1)){
            return false;
        }
        return true;
    });
}
int main(){
    vector<int> nums{3, 30, 34, 5, 9};
    largest_number(nums);
    for(int x: nums){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}