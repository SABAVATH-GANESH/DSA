class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1) return nums[i];
        }
        return x;
        
    }
};