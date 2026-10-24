class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<m;i++){
            mp2[t[i]]++;
        }
        int sum=0;
        int l;
       
        for(int i=0;i<n;i++){
            if(sum>=t.size()) break;
            if(mp2.find(s[i])!=mp2.end()){
                mp1[s[i]]++;
                if(mp1[s[i]]<=mp2[s[i]]){
                    sum++;
                    
                }
            }
           
            l=i;
        }
       
        if(sum<t.size()) return "";
        int start=0;
        while(start<=l && (mp2.find(s[start])==mp2.end() || mp1[s[start]]>mp2[s[start]])){
            if(mp2.find(s[start])!=mp2.end() ){
                mp1[s[start]]--;
            }
            start++;
        }
        
        
        
        int beststart=start;
        int end=l;
        int mini=l-start+1;
        for(int i=l+1;i<n;i++){
            if(mp2.find(s[i])!=mp2.end()){
                mp1[s[i]]++;
                cout<<s[i]<<mp1[s[i]]<<endl;
            }
           while(start<=i && (mp2.find(s[start])==mp2.end() || mp1[s[start]] > mp2[s[start]])){
            cout<<start<<endl;
            if(mp2.find(s[start])!=mp2.end() ){
                mp1[s[start]]--;
            }
            start++;
           }
           cout<<start;
           bool valid=true;
           for(auto it:mp1){
              if(mp1[it.first] < mp2[it.first]){
                valid=false;
                break;
              }
           }
           if(valid && i-start +1 <mini){
            mini=i-start +1;
            beststart=start;
            end=i;
           }


        }
        return s.substr(beststart,mini);

        
    }
};