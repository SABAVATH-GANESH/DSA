class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_map<char,int> mp;
        int start=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && start <=mp[s[i]]){
                start=mp[s[i]]+1;
                mp[s[i]]=i;
            }
            mp[s[i]]=i;
            maxi=max(maxi,i-start+1);
        }
        return maxi;
        
    }
};