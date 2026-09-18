class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        int st=intervals[0][0],en=intervals[0][1];
        
        for(int i=0;i<n;i++){
               if(en>=intervals[i][0]){
                en=max(en,intervals[i][1]);
               }
               else{
                ans.push_back({st,en});
                st=intervals[i][0];
                en=intervals[i][1];
               }
        }
        ans.push_back({st,en});
        return ans;
    }
};