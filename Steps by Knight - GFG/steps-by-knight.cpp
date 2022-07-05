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
	    int A=N, B=N, C=KnightPos[0],D=KnightPos[1], E=TargetPos[0], F=TargetPos[1];
	      int vis[A+1][B+1] = {0};

    queue<pair<int,int>> q;

    q.push({C,D});

    vis[C][D] = 1;

    int dx[] = {2,1,-1,-2,2,1,-2,-1};

    int dy[] = {-1,-2,-2,-1,1,2,1,2};

    int ans = 0;

    while(!q.empty())

    {

        int n = q.size();

        for(int i = 0; i < n; i++)

        {

            auto it = q.front();

            q.pop();

            int x = it.first;

            int y = it.second;

            if(x == E && y == F) return ans;

            for(int i = 0; i < 8; i++)

            {

                int xx = x + dx[i];

                int yy = y + dy[i];

                if(xx > 0 && xx <= A && yy > 0 && yy <= B && !vis[xx][yy])

                {

                    q.push({xx,yy});

                    vis[xx][yy] = 1;

                }

            }

        }

        ans++;

    }

    return -1;
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