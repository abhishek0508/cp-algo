// Given a valid sentence without any spaces between the words and a dictionary of valid
// English words, find all possible ways to break the sentence in individual dictionary words.
bool dictionaryContains(vector<string> dict, string sentence){
    for(int i=0;i<dict.size();i++){
        if(dict[i].compare(sentence)==0){
            return true;
        }
    }
    return false;
}
helper(string curr_str, int len, string result){
    
    for(int i=1;i<=len;i++){
        string prefix = sentence.substr(0,i);
        if(dictionaryContains(prefix)){
            if(i==n){
                result += prefix;
                cout<<result<<endl;
                break;
            }
            helper(curr_str.substr(i,n-i),n-i,result+prefix+" ");
        }
    }

}

vector<string> all_ways(vector<string> dict, string sentence){
    helper(sentence, sentence.length(), "");
} 