// [4,3,3] , 5 
// 3.14*4*4 = 50
// 1,1,1,2,2,3 => 3.14+3.14+3.14+12+12+27.13


// while l + 1e-5 <= r:
//         x = (l + r) / 2
//         if possible(x):
//             l = x
//         else:
//             r = x
// 



#include<bits/stdc++.h>
using namespace std;

int count(double mid, vector<double> arr, int guests){
    int count=0;
    
    for(int i=0;i<arr.size();i++){
        double area = arr[i]*arr[i]*3.14159;
        count += (int)(area/mid);
    }
    // cout<<"count="<<count<<endl;
    return count;
}

double fun(vector<double> arr,int guests){
    double x = (*max_element(arr.begin(),arr.end()));
    double l = 0.0,r=3.14159*x*x;

    cout<<"l="<<l<<"r="<<r<<endl;
    while(l<r){
        double mid = l+(r-l)/2.0;
        // cout<<"mid="<<mid<<endl;
        int c = count(mid,arr,guests);
        // cout<<"c="<<c<<endl;
        if(c < guests){
            r = mid-0.00001;
        }
        else{
            l = mid;
        }
    }
    return l;
}

int main(){
    int n;
    cin>>n;
    vector<double> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int guests;
    cin>>guests;
    double x = fun(arr,guests);
    printf("%.3f",x);
    return 0;
}

// 1,1,1,2,2,3 => 3.14+3.14+3.14+12+12+27.13
//  = 0.0, r=28.23
// mid = 14.1


// nth square root