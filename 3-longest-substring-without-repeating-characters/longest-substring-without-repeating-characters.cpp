class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int start=0;
        unordered_map<char,int> mp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && start<=mp[s[i]]){
                 start=mp[s[i]]+1;
                 sum=i-start+1;
            }else{
                sum++;
            }
            mp[s[i]]=i;
            maxi=max(maxi,sum);
        }
        return maxi;
        
    }
};