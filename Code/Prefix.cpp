string Solution::longestCommonPrefix(vector<string> &A) {
  int n=A.size();
  
  string x;
  
  x=A[0];
  int i=1;
  while(i<n){
      for(int j=0;j<x.length();j++){
          if(x[j]!=A[i][j]){
          x.erase(j);
          break;
      }
  }
  i++;
}

return x;
}
