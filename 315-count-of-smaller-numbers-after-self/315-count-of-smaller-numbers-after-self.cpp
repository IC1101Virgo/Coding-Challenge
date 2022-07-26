class Solution {
public:
    
    vector<int>ans;
    void mergeSort(int start, int end, vector<pair<int,int>> &a){
        if(start >= end)return;
        int mid = (start+end)/2;
        
        mergeSort( start, mid, a );
        mergeSort(mid+1, end, a);
        vector< pair<int, int> >temp(end-start+1);
        int i = start, j =mid+1, l=0;
        while( i<=mid && j<=end ){
            if(a[i].first>a[j].first){
                ans[a[i].second]+=end-j+1;
                temp[l++]=a[i++];
            }
            
            else{
                temp[l++]=a[j++];
            }   
        }
        while(i<=mid)temp[l++] = a[i++];
        while(j<=end)temp[l++] = a[j++];
        for(auto i: temp){
            a[start++] = i;
        }
        
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.resize(n);
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        
        mergeSort(0,n-1,v);
        return ans;
    }
};