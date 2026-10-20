class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        int lr=0,lc=0,ur=m-1,uc=n-1;
        int turn=0;
        int posc=0;
        int posr=0;
        vector<int> ans;
        int c=0,r=0;
        while(lr<=ur && lc<=uc){
            if(turn%2==0){
                if(posc%2==0){
                    
                    while(c<=uc){
                        ans.push_back(matrix[r][c]);
                        c++;
                    }
                    c--;
                    lr+=1;
                    r=lr;
                    posc=1;
                    
                }else{
                    while(c>=lc){
                        ans.push_back(matrix[r][c]);
                        c--;
                    }
                    c++;
                    ur-=1;
                    r=ur;
                    posc=0;

                }
                turn=1;
            }else{
                if(posr%2==0){
                    while(r<=ur){
                        ans.push_back(matrix[r][c]);
                        r++;
                    }
                    r--;
                    posr=1;
                    uc -=1;
                    c=uc;

                }else{
                    while(r>=lr){
                        ans.push_back(matrix[r][c]);
                        r--;
                    }
                    r++;
                    posr=0;
                    lc+=1;
                    c=lc;
                }
                turn=0;
            }
        }
        return ans;
    }
};