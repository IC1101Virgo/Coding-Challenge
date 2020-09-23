class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
         int tank = 0, startGas = 0, index = 0;
        
        for (size_t i = 0; i < gas.size(); i++) 
        {
            int start = gas[i] - cost[i];
            
            if (tank + start < 0) 
            {
                tank = 0;
                index = i + 1;
            } 
            else 
            {
                tank += start;
            }
            
            startGas += start;
        }
        
        return startGas >= 0 ? index : -1;
    }
    
};