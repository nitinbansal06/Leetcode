
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        sort(diff.begin(), diff.end(), greater<long long>());

        diff.push_back(0);

        for (int i = 0; i < n; i++) {
            long long count = i + 1;
            long long gap = diff[i] - diff[i + 1];
            long long cost = count * gap;

            if (k >= cost) {
                k -= cost;
                diff[i] = diff[i + 1];
            } else {
                long long reduction = k / count;
                long long remainder = k % count;
                long long level = diff[i] - reduction;

                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    long long d = level;
                    if (j < remainder) d--;
                    ans += d * d;
                }

                for (int j = i + 1; j < n; j++) {
                    ans += diff[j] * diff[j];
                }

                return ans;
            }
        }

        return 0;
    }
};
