class Solution {
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while(exp > 0) {
            if(exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long mi(long long n) {
        return power(n, MOD - 2);
    }
    long long nCr(int n, int r, const vector<long long>& fact) {
        if(r < 0 || r > n) return 0;
        return fact[n] * mi(fact[r]) % MOD * mi(fact[n - r]) % MOD;
    }
    
public:
    int countVisiblePeople(int n, int pos, int k) {
        if(k > n - 1) return 0;
        vector<long long> fact(n + 1);

        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        long long comb = nCr(n - 1, k, fact);

        return (comb * 2) % MOD;
    }
};