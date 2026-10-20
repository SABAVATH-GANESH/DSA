class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        unordered_map<int,bool> mp;
        unordered_map<int,bool> mp1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(!mp[i]){

                        mp[i]=true;
                    }
                    if(!mp1[j]){
                        mp1[j]=true;
                    }
            
                }
            }
        } 
        for(int r=0;r<m;r++){
            if(mp[r]){
                for(int i=0;i<n;i++){
                    matrix[r][i]=0;
                }
            }
        }
        for(int c=0;c<n;c++){
            if(mp1[c]){
                for(int i=0;i<m;i++){
                    matrix[i][c]=0;
                }
            }
        }
    }
};