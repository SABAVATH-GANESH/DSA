class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2 * limit + 2,0);
        

        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int mini=min(a,b)+1;
            int maxi=max(a,b)+limit;
            

             diff[2] +=2;
             diff[2*limit+1] -=2;

            diff[mini] +=(-1);
            diff[maxi+1] -=(-1);
           
            diff[a+b] +=(-1);
            diff[a+b+1] -=(-1);
            
        }
        int minval=INT_MAX;
        for(int i=2;i<=2*limit;i++){
             diff[i] +=diff[i-1];
             minval= min(minval,diff[i]);
        }
        return minval;

        
    }
};