
#include<bits/stdc++.h>
using namespace std;


// algorithm 1 -> simple recursion
// algorithm 2 -> if [i,j] is palidrome then a edge from i to j+1
// algorithm 3 -> dynamic programming -> cut[i] is min cut needed till ith position, to 
// find cut[i] = min(cut[j] for all j<i -> if [i,j] is palindrome)


// graph way
void min_cut(string str){

    // building look up table to determine whether my substring is paldindrome or not
    vector<vector<bool>> dp(str.length(),vector<bool>(str.length(),true));
    int n = str.length(), m = str.length();
    for(int k=1;k<=n-1;k++){
        int i=0,j=k;
        while(j<n){
            dp[i][j] = (str[i]==str[j] && dp[i+1][j-1]);
            i++;
            j++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // building graph for if substring(i,j) is palindrome, then edge from i->j+1
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(dp[i][j]==true){
                adj[i].push_back(j+1);
            }
        }
    }

    // using bfs to determine shortest path from 0 to n
    vector<int> dist(n+1,-1);
    dist[0]=0;

    queue<int> qu;
    qu.push(0);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        if(u == n){
            break;
        }

        vector<int> neig = adj[u];
        for(auto it = neig.rbegin();it!=neig.rend();it++){
            int v = *it;
            if(dist[v]==-1){
                qu.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }

    cout<<dist[n]-1<<endl;

    return;
}

// recursive way
bool isPalindrome(string s){
        int l=0,r=s.length()-1;
        while(l<r && s[l]==s[r]){
            l++;
            r--;
        }
        return l>=r;
    }
    
void helper(string str, int start, int end, int cut,int &min_cut){
    // cout<<"curr_str="<<curr_str<<endl;
    if(start>end){
        if(cut<min_cut){
            min_cut=cut;
        }
        return;
    }
    
    for(int i=1;i<=end-start+1;i++){
        string s = str.substr(start,i);
        if(isPalindrome(s)){
            helper(str,start+i,end,cut+1,min_cut);
        }
    }    
}
    
int min_cut_recursive(string s) {
    int min_cut=INT_MAX;
    helper(s,0,s.length()-1,0,min_cut);
    return min_cut-1;
}

int min_cut_dp(string str){
    
}

int main(){
    string str = "ccabaccdefe";
    min_cut(str);
    min_cut_recursive(str);
    min_cut_dp(str);
    return 0;
}