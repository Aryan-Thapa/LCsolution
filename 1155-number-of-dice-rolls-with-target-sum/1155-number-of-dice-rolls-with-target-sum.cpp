class Solution {
public:
    const int mod = 1000000007;

    int solve(int n, int k, int target, int count) {
        if (count == n && target == 0) return 1;
        if (count == n || target < 0) return 0;

        int recans = 0;
        for (int i = 1; i <= k; i++) {
            recans = (recans + solve(n, k, target - i, count + 1)) % mod;
        }
        return recans;
    }

    int memsolve(int n, int k, int target, int count, std::vector<std::vector<std::vector<int>>>& dp) {
        if (count == n && target == 0) return 1;
        if (count == n || target < 0) return 0;
        if (dp[n][target][count] != -1) return dp[n][target][count];

        int recans = 0;
        for (int i = 1; i <= k; i++) {
            recans = (recans + memsolve(n, k, target - i, count + 1, dp)) % mod;
        }
        dp[n][target][count] = recans;
        return recans;
    }

    int numRollsToTarget(int n, int k, int target) {
        std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(target + 1, std::vector<int>(n + 1, -1)));
        int count = 0;
        int ans = memsolve(n, k, target, count, dp);
        return ans;
    }
};


