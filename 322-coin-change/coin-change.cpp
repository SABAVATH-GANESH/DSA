class Solution {
public:
    long minicoin(vector<int>& c,int t,vector<int>& dp){
        if(t==0) return 0;
        if(dp[t]!=-1) return dp[t];
        int mini=INT_MAX;
        for(int i=0;i<c.size();i++){
            if(t-c[i]>=0){
               int sub=minicoin(c,t-c[i],dp);
               if(sub!=INT_MAX){
                mini=min(mini,1+sub);
               }
            }
            
        }
        return dp[t]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount + 1,-1);
        int ans=minicoin(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};