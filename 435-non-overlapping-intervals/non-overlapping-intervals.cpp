class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int e=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++){
            if(e>intervals[i][0]){
                ans++;
                e=min(intervals[i][1],e);
            }else{
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        return ans;
        
    }
};