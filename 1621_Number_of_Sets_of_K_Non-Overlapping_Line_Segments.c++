// 1621. Number of Sets of K Non-Overlapping Line Segments

//Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways 
//we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The 
//endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n 
//points, and they are allowed to share endpoints.
//Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, 
//return it modulo 109 + 7.

class Solution {
public:
    const long long MOD = 1000000007;

    long long dp[1001][1001];
    long long suffix[1001][1001];

    long long solve(int n, int K, int i) {
        if (K == 0)
            return 1;

        if (i >= n)
            return 0;

        if (dp[K][i] != -1)
            return dp[K][i];

        long long skip = solve(n, K, i + 1);

        long long take = getSuffix(n, K - 1, i + 1);

        return dp[K][i] = (skip + take) % MOD;
    }

    long long getSuffix(int n, int K, int i) {
        if (i >= n)
            return 0;

        if (suffix[K][i] != -1)
            return suffix[K][i];

        return suffix[K][i] =
            (solve(n, K, i) + getSuffix(n, K, i + 1)) % MOD;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        memset(suffix, -1, sizeof(suffix));

        return solve(n, k, 0);
    }
};

// T.C. - 0(n.k)
// S.C. - 0(n.k)