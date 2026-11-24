class Solution {
public:
    int prodct(vector<int> arr,int s,int e){
        int ans=1;
        for(int i=s;i<=e;i++){
            ans *=arr[i];
        }
        return ans;
    }
    int gcd1(int a,int b){
        if(b==0) return a;
        return gcd1(b,a%b);
    }
    
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int maxv=*max_element(nums.begin(),nums.end());
        int lc=1;
        for(int i=0;i<n;i++){
             lc=lcm(nums[i],lc);
        }

        for(int i=0;i<n;i++){
             long long g=0;
             long long l=1;
             long long p=1;
          for(int j=i;j<n;j++){
             g=gcd(nums[j],g);
             l=lcm(nums[j],l);
             p *=nums[j];
             
             if(p==g*l){
                ans=max(ans,j-i+1);
                cout<<p<<g<<l;
             }
             if(p>lc*maxv) break;

          }
        }
        
        return ans;
    }
};