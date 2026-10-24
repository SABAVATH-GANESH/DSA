class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0,maxlen=0,l=0,r=0;
        unordered_map<char,int> mp;
        while(r<s.size()){
            mp[s[r]] =1+mp[s[r]];
            maxf=max(maxf,mp[s[r]]);
            if(r-l+1-maxf > k){
                mp[s[l]]--;
                l++;
            }
            if(r-l+1-maxf <= k){maxlen=max(maxlen,r-l+1);}
            r++;
        }
        return maxlen;
    }
};