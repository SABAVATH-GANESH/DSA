class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prv;
        
        int left,right;
        prv.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            vector<int> curr;
            for(int j=0;j<=i;j++){
                if(j-1 <0){
                     left=0;
                }else{
                    left=prv[j-1];
                }
                if(j>=i) right=0;
                else right=prv[j];
                curr.push_back(left+right);

            }
            prv=curr;

        }
        return prv;

        
    }
};