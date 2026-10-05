class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int k=1;
       while(k>0){for(int i=n-2;i>=0;i--){
            int maxi=*max_element(nums.begin()+i+1,nums.end());
            if(maxi>nums[i]){
                sort(nums.begin()+i+1,nums.end());
            }
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    swap(nums[i],nums[j]);
                    l=1;
                    i=-1;
                    break;
                }
            }
        }
        k--;
       }
       for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
       }
        if(l==0){
            sort(nums.begin(),nums.end());
        }
    }
};