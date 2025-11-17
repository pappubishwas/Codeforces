#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

long long MOD = 998244353;

// Helper function to add with modulo
long long add(long long a, long long b) {
    return (a + b) % MOD;
}

// Helper function to subtract with modulo
long long sub(long long a, long long b) {
    return (a - b + MOD) % MOD;
}

// Function to compute possible multisets
// Returns a pair: {total_sum, dp_array}
pair<long long, vector<long long>> count_multisets(const map<int, int>& elements, int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (auto const& [val, count] : elements) {
        vector<long long> new_dp(n + 1, 0);
        for (int j = 0; j <= n; j++) {
            long long prev = (j > 0) ? new_dp[j - 1] : 0;
            new_dp[j] = add(prev, dp[j]);
            if (j > count) {
                new_dp[j] = sub(new_dp[j], dp[j - count - 1]);
            }
        }
        dp = new_dp;
    }

    long long total_sum = 0;
    for (long long ways : dp) {
        total_sum = add(total_sum, ways);
    }
    
    // total_sum is the total number of multisets (including empty)
    // dp is the array of counts by size
    return {total_sum, dp};
}

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    int max_freq = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        counts[a]++;
        max_freq = max(max_freq, counts[a]);
    }

    map<int, int> max_group;
    map<int, int> other_group;
    int n_other = 0;
    int num_max = 0;

    for (auto const& [val, count] : counts) {
        if (count == max_freq) {
            max_group[val] = count;
            num_max++;
        } else {
            other_group[val] = count;
            n_other += count;
        }
    }

    auto [total_max, dp_max] = count_multisets(max_group, n);
    auto [total_other, dp_other] = count_multisets(other_group, n);
    long long zero_max = dp_max[0]; // This is 1

    long long ans = 0;

    // Case 2: Must pick at least one from max_group
    if (num_max > 1 || max_freq > n_other) {
        ans = sub(total_max, zero_max) * total_other % MOD;
    } 
    // Case 1: The tricky one (TC 4)
    else {
        // Num_max == 1 AND max_freq <= n_other
        // We can form (empty, non-empty), but some are impossible
        
        // 1. Calculate all combinations
        long long all_combinations = total_max * total_other % MOD;
        
        // 2. Find impossible (empty, s_other) sets
        // An s_other of size j is impossible if j > n_other - max_freq
        // (Not enough "other" items left to hide the max_freq items)
        long long impossible_count = 0;
        int impossible_threshold = n_other - max_freq;
        for (int j = impossible_threshold + 1; j <= n; j++) {
            impossible_count = add(impossible_count, dp_other[j]);
        }
        
        // 3. Subtract impossible sets, and subtract the 1 empty-empty set
        // ans = all_combinations - impossible_count - 1
        ans = sub(all_combinations, impossible_count);
        ans = sub(ans, 1);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}