class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2,nums.end());
        map<int,set<int>> mp;
        for(int i=0;i<(1<<(n/2));i++){
            int sum=0,cnt=0;
            for(int j=0;j<n/2;j++){
                if(i & 1<<j){
                    sum +=left[j];
                    cnt++;
                }
            }
            mp[cnt].insert(sum);
        }
        int ans=INT_MAX;
        for(int i=0;i<(1<<(n/2));i++){
            int sum=0,cnt=0;
            for(int j=0;j<n/2;j++){
                if(i & 1<<j){
                    sum +=right[j];
                    cnt++;
                }
            }
            int need=(n/2)-cnt;
            if(mp.find(need)!=mp.end()){
                int remainsum=(tot/2)-sum;
                auto it=mp[need].lower_bound(remainsum);
                if(it !=mp[need].end()){
                    int s=sum + *it;
                    ans =min(ans,abs((tot-s)-s));
                }
                if(it != mp[need].begin()){
                    it--;
                     int s=sum + *it;
                    ans =min(ans,abs((tot-s)-s));
                }
                
            }
        }
        return ans;
    }
};