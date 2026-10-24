class Solution {
public:
    int characterReplacement(string s, int k) {
      int l=0,r=0,maxf=0,maxlen=0;
      unordered_map<char,int> mp;
      while(r<s.size()){
        // upto r what is maxf and if r - l + 1 - maxf > k then you need move l++ because we only
        // change or replace upto k char so normally we do while r-l+1-maxf > k we do l++;
        // but here the time complexcity is O(N + N)* 26 becase we changeing maxf if after every checking in while loop
        // so we need decrease time with these concept is if k=2 ,replacechar = 3, and maxf=3 at most maxf is 3 we get maxlen=4 but we are runing while loop for find max and till r-l+1-max <=k so here ans not change because at most we get maxlen =5 if maxf =3 if we decrse maxf=2 the maxlen  not change so we only move l++ if (r - l + 1 - maxf > k) so here time complexty is O(N);

        //solution of O(N+N)*26;
        mp[s[r]] ++;
        maxf=max(maxf,mp[s[r]]);
        while(r-l+1-maxf >k){ // l++ 
            mp[s[l]]--;
            l++;
            maxf=0;
            int j=0;
            
            for(char i='A';i<='Z';i++){
                maxf=max(maxf,mp[i]);
            }
        }
        if(r - l + 1 - maxf <=k){
            maxlen=max(maxlen,r - l + 1);
        }
        r++;


      } 
      return maxlen; 
    }
};