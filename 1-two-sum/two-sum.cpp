class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());

        int i=0,j=n-1;
        vector<int> ans;
        while(i<j){
            if(nums[i]+nums[j]==target){
                if(nums[i]==nums[j]){
                    ans.push_back(mp[nums[i]][0]);
                    ans.push_back(mp[nums[i]][1]);
                }else{
                ans.push_back(mp[nums[i]][0]);
                ans.push_back(mp[nums[j]][0]);
               
                }
                break;
            }else if(nums[i]+nums[j]>target){
                j--;
            }else{
                i++;
            }
            
        }
        return ans;
    }
};