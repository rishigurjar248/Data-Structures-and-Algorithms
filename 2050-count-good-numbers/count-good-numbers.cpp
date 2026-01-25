class Solution {
public:
    static const long long MOD = 1000000007;

     long long power(long long a, long long b) {
        long long ans = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;  // positions 0,2,4...
        long long oddPos  = n / 2;        // positions 1,3,5...

        long long res = (power(5, evenPos) * power(4, oddPos)) % MOD;
        return (int)res;
    }
};