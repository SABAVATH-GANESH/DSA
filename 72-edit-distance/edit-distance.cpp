class Solution {
public:
    int sol(int i,int j,string &w1,string &w2,vector<vector<int>>& dp){
        if(i<0 && j<0) return 0;
        if(i>=0 &&j<0) return i+1;
        if(i<0 && j>=0) return j+1;
        if(dp[i][j]!=0) return dp[i][j];
        if(w1[i]==w2[j]){
            dp[i][j]=sol(i-1,j-1,w1,w2,dp);
        }else {
            dp[i][j]=1+sol(i-1,j,w1,w2,dp);
            dp[i][j]=min(dp[i][j],1+sol(i,j-1,w1,w2,dp));
            dp[i][j]=min(dp[i][j],1+sol(i-1,j-1,w1,w2,dp));
        }
        return dp[i][j];

    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        cout<<m<<n;
        return sol(m-1,n-1,word1,word2,dp);
        
    }
};