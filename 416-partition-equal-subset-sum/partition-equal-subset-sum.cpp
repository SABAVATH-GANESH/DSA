class Solution {
public:
    bool sol(vector<int>& nums,int i,int val,int tot,vector<vector<int>>& dp){
        if(i>=nums.size()){
            if(tot-val==val) return true;
            return false;
        }
        if(dp[i][val]!=-1) return dp[i][val];
        bool take=sol(nums,i+1,val+nums[i],tot,dp);
        bool skip=sol(nums,i+1,val,tot,dp);
        return dp[i][val]=skip|take;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(tot+1,-1));
        return sol(nums,0,0,tot,dp);
        
    }
};