
class Solution {
public:
    bool sol(string s,vector<string>& w,string val,vector<int> & dp){
        if(s==val) return true;
        if(s.size()<val.size()) return false;
        
        if(dp[val.size()]!=-1) return dp[val.size()];
        
        bool ans=false;
        for(int i=0;i<w.size();i++){
            if(val.size()<s.size() && s.find(val+w[i])==0){
                ans=sol(s,w,val+w[i],dp);
                if(ans==true) return dp[val.size()]=true;
            }
        }
        return dp[val.size()]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return sol(s,wordDict,"",dp);
    }
};
