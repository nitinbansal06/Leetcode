class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<uint8_t> isPrime(n, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (long long i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                for (long long j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = 0;
                }
            }
        }
        int count = 1;
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};