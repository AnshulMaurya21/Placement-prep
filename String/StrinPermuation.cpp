#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(int start, string &str, vector<string> &ans){
        if(start==str.size()){
            ans.push_back(str);
            return;
        }
        
        for(int i=start; i<str.size(); i++){
            swap(str[i],str[start]);
            solve( start+1, str, ans );
            swap(str[i],str[start]);        
        }
    }
        
    vector<string> permutation(string str)
    {
        vector<string> ans;
        solve(0,str,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};