class Solution {
public:
    string frequencySort(string s) {
          unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
        s="";   
        while(!maxheap.empty()){
            int x=maxheap.top().first;
            
            for(int i=0;i<x;i++)
                s+=maxheap.top().second;
            //frequency times the character
            maxheap.pop();
        }
        return s;
    }
};