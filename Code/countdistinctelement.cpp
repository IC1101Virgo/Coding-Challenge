class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int>m;
        vector<int> v;
        
        for(int i=0;i<k;i++)
        m[A[i]]++;
       // int i=0;
       v.push_back(m.size());
        
        for(int i=k;i<n;i++){
            m[A[i-k]]--;
            if(m[A[i-k]]==0)
            m.erase(A[i-k]);
            m[A[i]]++;
            v.push_back(m.size());
        }
        
        return v;
    }
};
