class Solution {
public:
     static bool compare(int a, int b){
        string x=to_string(a);
        string y=to_string(b);
        
        return (x+y)>(y+x);

    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        
        string s="";
        
        sort(nums.begin(),nums.end(),compare);
        
        int count=0;
        
        for(int i=0;i<n;i++){
            s+=to_string(nums[i]);
            
            if(nums[i]==0)
                count++;
        }
        
        return count==n? "0":s;
    }
};