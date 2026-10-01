class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
      
        vector<int> o;
        for(int i=0;i<n;i++){
            o.push_back(gas[i]-cost[i]);
            
        }
        int t=0;
        int sum=0;
        int index=0;
        
        for(int i=0;i<n;i++){
            t +=o[i];
            sum +=o[i];
          
            if(sum<0){
                sum=0;
                index=i+1;  
            }
             
            
        }
        
        if(t<0){
            return -1;
        }
        
        return index;
        
    }
};