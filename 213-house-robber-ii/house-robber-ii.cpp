class Solution {
public:
    int sol(vector<int>& nums,int i,int e,vector<int>& dp){
        if(i>=e) return 0;
        if(dp[i]!=-1) return dp[i];
        int take =nums[i]+ sol(nums,i+2,e,dp);
        int skip=sol(nums,i+1,e,dp);
        return dp[i]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        vector<int> dp1(n+1,-1);
        return max(sol(nums,0,n-1,dp),sol(nums,1,n,dp1));
    }
};