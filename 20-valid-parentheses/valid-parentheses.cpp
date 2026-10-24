class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        if(n==1) return false;
        for(int i=0;i<n;i++){
             if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
             }else{
                if(s[i]==')'){
                    if(st.empty() || st.top()!='(') return false;
                }else if(st.empty() || s[i]=='}'){
                    if(st.empty() || st.top()!='{') return false;
                }else{
                    if(st.top()!='[') return false;
                }
                st.pop();
             }
        }
        if(!st.empty()) return false;
        return true;
        
    }
};