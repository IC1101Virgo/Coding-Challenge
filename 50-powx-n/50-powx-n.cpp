class Solution {
public:
    double myPow(double x, long n) {
        if(n==0)
            return 1;
        
        if(x==0)
            return 0;
        
        if(n==1)
            return x;
        
        if(n<0)
            return myPow(1/x, -n);
        
        double num= myPow(x*x, n/2);
        
        if(n%2 != 0)
            num*=x;
        
        return num;
        
        
    }
};