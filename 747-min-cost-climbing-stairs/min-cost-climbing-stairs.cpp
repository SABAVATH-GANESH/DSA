class Solution {
public:
    int sol(vector<int>& c,int i,vector<int>& dp){
        if(i>=c.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int one=INT_MAX,two=INT_MAX;
        one=c[i]+sol(c,i+1,dp);
        two=c[i]+sol(c,i+2,dp);
        dp[i]=min(one,two);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        vector<int> dp1(n+1,-1);
        return min(sol(cost,0,dp),sol(cost,1,dp));
        
    }
};