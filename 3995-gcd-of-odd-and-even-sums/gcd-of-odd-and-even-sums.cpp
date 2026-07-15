class Solution {
public:
    int minimum(int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = (n+1) * n;
        int gcd = 1;

        for(int i = 2;i<=(minimum(sumOdd,sumEven)/2);i++)
        {
            if((sumOdd%i==0) && (sumEven%i==0))
            {
                gcd = i;
            }
        }

        return gcd;
    }
};