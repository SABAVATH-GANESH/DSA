class Solution {
public:
    long minicoin(vector<int>& c,int t,vector<vector<int>>& dp,int i){
        if(t==0) return 0;
        if(t<0 || i>=c.size()) return INT_MAX;
        if(dp[t][i]!=-1) return dp[t][i];
        int take=INT_MAX;
        
        if(t-c[i]>=0){
            int val=minicoin(c,t-c[i],dp,i);
            if(val!=INT_MAX){
                take=1+val;
            }else{
                take=INT_MAX;
            }
        }
        int skip=minicoin(c,t,dp,i+1);
        return dp[t][i]=min(take,skip);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(amount + 1,vector<int>(n,-1));
        int ans=minicoin(coins,amount,dp,0);
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};