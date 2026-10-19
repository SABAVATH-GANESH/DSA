class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l;
        if(n==2) return 0;
        for(int i=0;i<n;i++){
            if(i+1<n &&height[i]>height[i+1]){
                l=i;
                break;
            }
        }
        int sum=0;
        int last;
        for(int i=l;i<n;i++){
            int j=i+1;
            last=i;
            while(j<n && height[i]>height[j]){
                j++;
            }
           
            for(int k=i+1;k<j && j<n;k++){
                sum +=height[i]-height[k];
            }
            i=j-1;
            
        }
        int temp=n-1;
        while(temp-1>=last && height[temp]<height[temp-1]){
            temp--;
        }
        cout<<temp;
        for(int i=temp;i>=last;i--){
            int j=i-1;
             while(j>=last && height[i]>height[j]){
                j--;
            }
            for(int k=i-1;k>j && j>=last;k--){
                sum +=height[i]-height[k];
            }
            i=j+1;

        }
        return sum;
    }
};