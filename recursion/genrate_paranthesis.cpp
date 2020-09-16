// https://leetcode.com/problems/generate-parentheses/

void helper(string str, int pos, int n, int count, vector<string> &res){
    if(pos==n){
        if(count==0){
            res.push_back(str);
        }
        return;
    }
    
    if(count==0){
        helper(str+"(",pos+1,n,count+1,res);
    }
    else{
        helper(str+"(", pos+1, n, count+1, res);
        helper(str+")", pos+1, n, count-1, res);
    }
}
vector<string> generateParenthesis(int n) {
    string str="";
    vector<string> res;
    helper(str,0,2*n,0,res);
    return res;
}

// time complexity will be O(4^n/sqrt(n))
// since it turns out be nth catalan number -> hence (2nCn/(n+1)) which is more read lc article
