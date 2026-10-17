class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int nozero=0;
        int n=nums.size();
        int product=1;
        for(int i=0;i<n;i++){
             if(nums[i]!=0){
                   product *=nums[i];
             }else{
                nozero++;
             }
        }
        vector<int> ans(n,0);
        if(nozero>1){
               return ans;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && nozero==0){
                ans[i]=product/nums[i];
            }else{
                if(nums[i]==0){
                    ans[i]=product;
                }else{
                    ans[i]=0;
                }
            }
        }
        return ans;
    }
};