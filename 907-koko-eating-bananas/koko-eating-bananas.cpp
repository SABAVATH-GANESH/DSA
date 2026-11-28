class Solution {
public:
    bool check(vector<int>& p,int m,int h){
        long long l=0;
        for(int i=0;i<p.size();i++){
            l +=(p[i]+m-1)/m;
            if(l>h) return false;
        }
        return true;
    }
    int bs(vector<int>& p,int h,int s, int e,int ans){
        if(s>e) return ans;
        int mid=s+(e-s)/2;
        if(check(p,mid,h)){
            return bs(p,h,s,mid-1,mid);

        }
        return bs(p,h,mid+1,e,ans);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        
        
        int ans=bs(piles,h,s,e,e);

        return ans;
        
    }
};