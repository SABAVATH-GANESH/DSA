class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2*limit+2,0);
       

        for(int i=0;i<n/2;i++){
            diff[2] +=2;
            diff[2*limit+1] +=(-2);
            int a=nums[i];
            int b=nums[n-i-1];
            int mini=min(a,b);
            int maxi=max(a,b);
            int l=mini+1;
            int r=maxi+limit;
            if(l<=2*limit) diff[l] +=(-1);
            if(r+1<= 2*limit+1) diff[r+1] -=(-1);
            if(a+b <=2*limit){
                diff[a+b] +=(-1);
                diff[a+b+1] -=(-1);
            }
        }
        int minval=diff[2];
        for(int i=3;i<2*limit+2-1;i++){
             diff[i] +=diff[i-1];
             minval= min(minval,diff[i]);
        }
        return minval;

        
    }
};