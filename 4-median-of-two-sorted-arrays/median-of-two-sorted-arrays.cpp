class Solution {
public:
    double sol(vector<int> & nums1,vector<int>& nums2,int low,int high){
        int m=nums1.size();;
        int n=nums2.size();
        //partion findd chyala 
        int left=(n+m+1)/2;
        int cut1=(low+high)/2;
        int cut2=left-cut1;
        double l1=INT_MIN,r1=INT_MAX;
        double l2=INT_MIN,r2=INT_MAX;
        double ans;
        if(cut1-1>=0) l1=nums1[cut1-1];
        if(cut1<nums1.size()) r1=nums1[cut1];
        
        if(cut2-1>=0) l2=nums2[cut2-1];
        if(cut2<nums2.size()) r2=nums2[cut2];
        while(low<=high){

             cut1=(low+high)/2;
             cut2=left-cut1;
             
            if(cut1-1>=0) l1=nums1[cut1-1];
            else l1=INT_MIN;
            if(cut1<nums1.size()) r1=nums1[cut1];
            else r1=INT_MAX;
        
            if(cut2-1>=0) l2=nums2[cut2-1];
            else l2=INT_MIN;
            if(cut2<nums2.size()) r2=nums2[cut2];
            else r2=INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((nums1.size()+nums2.size())%2 !=0) return max(l1,l2);
                 return (max(l1,l2)+min(r1,r2))/2.0;

            }


            if(l1>r2) high -=1;
            else low+=1;
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();;
        int n=nums2.size();
        if(n==1 && m==1) return (nums1[0]+nums2[0])/2.0;
        //partion findd chyala 
        int left=(n+m+1)/2;
        int low,high;
        double ans;
        if(m<n){
         low=0;high=m;
         ans=sol(nums1,nums2,low,high);
        }else{
            low=0;high=n;
            ans=sol(nums2,nums1,low,high);
        }
        return ans;
       

    }
};