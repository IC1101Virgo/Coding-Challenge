// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


void insert(stack<int> &s, int x){
   if(s.size()==0 || s.top()<=x){
       s.push(x);
       return;
   }
   int temp= s.top();
   s.pop();
   insert(s,x);
   s.push(temp);
   return;
}

void SortedStack :: sort()
{
  //Your code here
  if(s.size()==1){
      return;
  }
  int temp= s.top();
  s.pop();
  sort();
  insert(s,temp);
  return;
}