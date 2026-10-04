class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        long long max_far=LLONG_MIN;
        long long min_far=LLONG_MAX;

        long long max_p=LLONG_MIN;
        for(int j=m-1;j<n;j++){
            long long current=nums[j-m+1];
            max_far=max(max_far,current);
            min_far=min(min_far,current);
            long long p1=1LL*nums[j]* max_far;
            long long p2=1LL*nums[j] * min_far;

            max_p=max(max_p,max(p1,p2));
        }
        return max_p;
    }
};