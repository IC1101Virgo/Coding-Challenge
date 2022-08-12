class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int idx=0, tank=0, sg=0;
        
        for(int i=0; i<n; i++){
            int start = gas[i]-cost[i];
            
            if(tank+start<0){
                tank=0;
                idx=i+1;
            }
            
            else tank+=start;
            
            sg+=start;
        }
        
        return sg>=0?idx:-1;
    }
};