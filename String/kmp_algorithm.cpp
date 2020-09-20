// return all the occurence of pattern in text
// let us suppose our "text" is of length 10, and pattern is of length "4",
// if pattern doesn't matches at some point, we don't start over again.
// this is where kmp does the trick, is preprocesses the pattern. and generates a lps array
// longest proper prefix which is also suffix -> lps
// A proper prefix is prefix with whole string not allowed.
// For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”.
// Proper prefixes are “”, “A” and “AB”. Suffixes of the string are “”, “C”, “BC” and “ABC”.
// lps[i] = the longest proper prefix of pat[0..i] . which is also a suffix of pat[0..i]. 

vector<int> preprocesses(string pattern){
    int len=0;
    lps[0]=0;
    int i=1;
    vector<int> lps(pattern.length(),0);
    while(i < pattern.length()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(string text, string pat){
    vector<int> index;
    vector<int> lps = preprocesses(pat);

    int n = text.length();
    int m = pat.length();
    int i=0,j=0;

    while(i<n){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        
        if(j==m){
            index.push_back(i-m);
            j = lps[j-1];
        }
        else if(i<n && text[i]!=pat[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}
