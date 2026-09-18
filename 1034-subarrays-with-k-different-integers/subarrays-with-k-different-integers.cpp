class Solution {
public:
    int sol(vector<int> &nums,int k){
        if(k==0) return 0;
        unordered_map<int,int> mp;
        int l=0,r=0;
        int c=0;
        while(r<nums.size()){
        mp[nums[r]]++;
        while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;

        }
        
        c +=(r-l+1);
        r++;
        }
       return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return sol(nums,k)-sol(nums,k-1);

    }
};