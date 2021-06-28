int hourglassSum(vector<vector<int>> a) {
    int sum=0,temp=INT32_MIN;
   
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           
           sum=(a[i][j]+a[i][j+1]+a[i][j+2])+(a[i+2][j]+a[i+2][j+1]+a[i+2][j+2])+(a[i+1][j+1]);
           
           if(sum>temp)
           temp=sum;
           
           
       }
   }
   
   return temp;
}
