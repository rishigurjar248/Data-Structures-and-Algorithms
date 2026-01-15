class Solution {
public:
     double myPow(double x, int n) {
        long long m=n;
        double mul=1.0;
        if(m<0) m=-1*m;
         
        while(m>0){
            if(m%2==1){
              mul=mul*x;
              m--;
            } 
            else{
                x=x*x;
                m=m/2;
            }
        }
        if(n<0) return (1/mul);
        else return mul;
    }
};