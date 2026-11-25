class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;

        string s1=s;
        reverse(s1.begin(),s1.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        int maxi=1;
        int ind=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;

                    if(i-dp[i][j]==n-j && maxi<dp[i][j]){
                        maxi=dp[i][j];
                        ind=j-1;
                    }
                }
            }
        }

        return s1.substr(ind-maxi+1,maxi);
    }
};