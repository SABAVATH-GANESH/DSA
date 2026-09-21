class Solution {
public:
   
    void sol(vector<int>& nums,vector<vector<int>> & result,int i){
        if(i>=nums.size()){
            
                  result.push_back(nums);
                 
           
            return;
        }
        unordered_set<int> st;
        for(int j=i;j<nums.size();j++){
            if(st.find(nums[j])!=st.end()) continue;
            st.insert(nums[j]);
            swap(nums[i],nums[j]);
            sol(nums,result,i+1);
            swap(nums[i],nums[j]);
        }



    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        sol(nums,result,0);
        return result;
        
        
    }
};