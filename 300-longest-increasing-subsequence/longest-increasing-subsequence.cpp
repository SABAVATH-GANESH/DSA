class Solution {
public:
    int sol(vector<int>& nums,int val,int i,vector<vector<int>> & dp,int offset){
        if(i>=nums.size()) return 0;
        int ind=offset+val;
        if(dp[i][ind]!=-1) return dp[i][ind];
        int take=0,skip=0;
        if(val<nums[i]){
            take =1+sol(nums,nums[i],i+1,dp,offset);
        }
        skip=sol(nums,val,i+1,dp,offset);
        return dp[i][ind]=max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<vector<int>> dp(n,vector<int>(abs(mini-1)+maxi+1,-1));
        int offset=abs(mini-1);
        return sol(nums,mini-1,0,dp,offset);
        
    }
};