class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();

        unordered_map<string, int> mp;

        for(auto ele: arr){
            mp[ele]++;
        }
        
        int i=0;

        while(i<n){
            if(mp[arr[i]] == 1){
                k--;

                if(k==0)
                return arr[i];

                i++;
            }

            else i++;

        }

        return "";
    }
};