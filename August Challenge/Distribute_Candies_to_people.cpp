class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> v(num_people,0);
            int i=0;
        while(candies>0)
        {
            v[i%num_people]+=i+1;
            candies-=i+1;
            i++;
        }
        if(candies<0)
        v[(i-1)%num_people]-=abs(candies);
        
        return v;
    }
    
};