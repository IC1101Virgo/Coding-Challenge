class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
      unordered_map<int, vector<int>> numToIndex;
        int result=0;
        for (int i=0;i<nums.size(); i++){
		
            if (numToIndex.find(nums[i])!=numToIndex.end()){ 
                for (int pos: numToIndex[nums[i]]){
                    if ( (pos*i)%k == 0){
                        result++;
                    }
                }
                numToIndex[nums[i]].push_back(i);
            }else{
                numToIndex[nums[i]]={i};            
            }
        }
        return result;
    }
};