class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        string s1=s;
        while(n>k){
            string s2="";
            int sum=0;
            for(int i=0;i<n;i++){
                sum +=s1[i]-'0';
                if((i+1)%k ==0 || i==n-1){
                   s2 +=to_string(sum);
                  
                   sum=0;
                }
            }
            
            s1=s2;
            n=s1.size();
        }
        return s1;
        
    }
};