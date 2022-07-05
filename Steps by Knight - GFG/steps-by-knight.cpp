// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;
	    int dx[8]={1,2,-2,-1,-1,-2,2,1};
	    int dy[8]={-2,-1,1,2,-2,-1,1,2};
	    vector<vector<int>>dis(N,vector<int>(N,0));
	    queue<vector<int>>q;
	    q.push({KnightPos[0]-1,KnightPos[1]-1});
	    while(!q.empty())
	    {
	        auto v = q.front();
	        q.pop();
	        int x = v[0];
	        int y=v[1];
	        for(int i=0;i<8;i++)
	        {
	            if(x+dx[i]>=0 && x+dx[i]<N && y+dy[i]>=0 && y+dy[i]<N && dis[x+dx[i]][y+dy[i]]==0) 
	             {
	                 dis[x+dx[i]][y+dy[i]] = dis[x][y]+1;
	                 q.push({x+dx[i],y+dy[i]});
	             }
	        }
	    }
	 return dis[TargetPos[0]-1][TargetPos[1]-1];  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends