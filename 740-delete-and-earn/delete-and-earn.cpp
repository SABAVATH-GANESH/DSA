class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> sum(maxi+1,0);
        for(auto num:nums){
             sum[num] +=num;
        }
        vector<int> dp(maxi+1,0);
        dp[0]=sum[0];
        dp[1]=max(sum[0],sum[1]);
        for(int i=2;i<=maxi;i++){
            int pick=sum[i]+dp[i-2];
            int npick=dp[i-1];
            dp[i]=max(pick,npick);
        }
        return dp[maxi];
    }
};