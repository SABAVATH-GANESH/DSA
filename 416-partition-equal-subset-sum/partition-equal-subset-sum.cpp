class Solution {
public:
    bool sol(vector<int>& nums,int tot,int i,int val,vector<vector<int>>& dp){
        if(tot-val==val) return true;
        if(i>=nums.size() || tot-val < val) return false;
        if(dp[val][i]!=-1) return dp[val][i];
        bool take=sol(nums,tot,i+1,val+nums[i],dp);
        bool skip=sol(nums,tot,i+1,val,dp);
        return dp[val][i]=(take|skip);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(tot+1,vector<int>(n+1,-1));
        return sol(nums,tot,0,0,dp);
        
    }
};