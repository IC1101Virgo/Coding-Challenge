class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index=0, startgas=0, tank=0;
      int n=gas.size();
        
      for(int i=0;i<n;i++){
          int start=gas[i]-cost[i];
          
          if(tank+start<0){
              tank=0;
              index=i+1;
          }
          
          else tank+=start;
          
          startgas+=start;
          
      }
      
      return startgas>=0?index:-1;
    }
};