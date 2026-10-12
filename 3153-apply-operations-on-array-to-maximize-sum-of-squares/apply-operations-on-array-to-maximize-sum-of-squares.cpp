
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        vector<int> cnt(31, 0);
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (num & (1LL << b)) {
                    cnt[b]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
