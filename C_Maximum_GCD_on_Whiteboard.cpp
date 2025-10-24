// // #include <bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace std;
// // using namespace __gnu_pbds;
// // mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// // template <class T>
// // using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// // int cost[200005]; 

// // int solve() {
// //     int n;
// //     long long k;
// //     cin >> n >> k;
// //     map<int, int> counts;
// //     for (int i = 0; i < n; ++i) {
// //         int a;
// //         cin >> a;
// //         counts[a]++;
// //     }

// //     for (int d = n; d >= 1; --d) {
// //         long long totalCost = 0;

// //         if (d > n / 3) {
// //             for (auto const& [x, count] : counts) {
// //                 if (x % d != 0) {
// //                     totalCost += count;
// //                 }
// //             }
// //         } else {
// //             for (int x = 1; x <= n; ++x) {
// //                 if (x % d == 0) {
// //                     cost[x] = 0;
// //                 } else {
// //                     cost[x] = 1;
// //                     if (x >= 3) {
// //                         for (int x1 = 1; x1 <= x / 3; ++x1) {
// //                             if (cost[x1] == 0) {
// //                             }
// //                         }
// //                         for (int k1 = 1; k1 * d * 3 <= x; ++k1) {
// //                             int x1 = k1 * d;
// //                             int mnx3 = (int)ceil((x - x1) / 2.0);
// //                             int mxx3 = x - 2 * x1;

// //                             if (mnx3 > mxx3) continue;

// //                             int first_valid_x3 = (int)ceil(mnx3 / (double)d) * d;

// //                             if (first_valid_x3 <= mxx3) {
// //                                 cost[x] = 0;
// //                                 break;
// //                             }
// //                         }
// //                     }
// //                 }
// //             }
// //             for (auto const& [x, count] : counts) {
// //                 totalCost += (long long)count * cost[x];
// //             }
// //         }

// //         if (totalCost <= k) {
// //             return d;
// //         }
// //     }
// //     return 1;
// // }

// // int main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         cout << solve() << "\n";
// //     }
// //     return 0;
// // }




// // #include <bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace std;
// // using namespace __gnu_pbds;
// // mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// // template <class T>
// // using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// // int cost[200005]; 

// // int solve() {
// //     int n;
// //     long long k;
// //     cin >> n >> k;
    
// //     vector<int> counts(n + 1, 0);
// //     int num = 0; 
// //     for (int i = 0; i < n; ++i) {
// //         int a;
// //         cin >> a;
// //         counts[a]++;
// //         num++;
// //     }

// //     for (int d = n; d >= 1; --d) {
// //         long long totalCost = 0;

// //         if (d > n / 3) {
// //             totalCost = num; 
// //             if (counts[d] > 0) {
// //                 totalCost -= counts[d];
// //             }
// //             if (2 * d <= n && counts[2 * d] > 0) {
// //                 totalCost -= counts[2 * d];
// //             }
// //         } else {
// //             for (int x = 1; x <= n; ++x) {
// //                 if (x % d == 0) {
// //                     cost[x] = 0;
// //                 } else {
// //                     cost[x] = 1; 
// //                     if (x >= 3) {
                    
// //                         for (int k1 = 1; ; ++k1) {
// //                             int x1 = k1 * d;
// //                             if (x1 > x / 3) break; 
// //                             int mnx3 = (int)ceil((x - x1) / 2.0);
// //                             int mxx3 = x - 2 * x1;

// //                             if (mnx3 > mxx3) continue;

// //                             int fvx3 = (int)ceil(mnx3 / (double)d) * d;
// //                             if (fvx3 == 0) { 
// //                                 if (mnx3 <= d) fvx3 = d;
// //                                 else continue;
// //                             }


// //                             if (fvx3 <= mxx3) {
// //                                 cost[x] = 0; 
// //                                 break;
// //                             }
// //                         }
// //                     }
// //                 }
// //             }
// //             for (int x = 1; x <= n; ++x) {
// //                 if (counts[x] > 0) {
// //                     totalCost += (long long)counts[x] * cost[x];
// //                 }
// //             }
// //         }

// //         if (totalCost <= k) {
// //             return d;
// //         }
// //     }
// //     return 1; 
// // }

// // int main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         cout << solve() << "\n";
// //     }
// //     return 0;
// // }






// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;

// int a_counts[200005];
// int dp[200005];
// int cost_for_d[200005];

// void precompute_dp(int n) {
//     for (int i = 1; i <= n; ++i) dp[i] = i;

//     for (int x1 = 1; x1 <= n / 3; ++x1) {
//         for (int x3 = x1;; ++x3) {
//             int x_min = 2 * x1 + x3;
//             if (x_min > n) break;
//             int x_max = min(n, x1 + 2 * x3);
//             int d_new = __gcd(dp[x1], dp[x3]);
//             for (int x = x_min; x <= x_max; ++x) {
//                 int x2 = x - x1 - x3;
//                 if (x2 >= x1) dp[x] = max(dp[x], d_new);
//             }
//         }
//     }
// }

// int solve() {
//     int n;
//     long long k;
//     cin >> n >> k;

//     for (int i = 1; i <= n; ++i) {
//         a_counts[i] = 0;
//         dp[i] = 0;
//         cost_for_d[i] = 0;
//     }

//     for (int i = 0; i < n; ++i) {
//         int a;
//         cin >> a;
//         a_counts[a]++;
//     }

//     for (int d = 1; d <= n; ++d) {
//         for (int x = d; x <= n; x += d) dp[x] = 0;

//         for (int x1 = 1; x1 <= n / 3; ++x1) {
//             if (dp[x1] == 0) {
//                 for (int x3 = x1;; ++x3) {
//                     if (dp[x3] == 0) {
//                         int x_min = 2 * x1 + x3;
//                         if (x_min > n) break;
//                         int x_max = min(n, x1 + 2 * x3);
//                         for (int x = x_min; x <= x_max; ++x) {
//                             if (dp[x] != 0) {
//                                 int x2 = x - x1 - x3;
//                                 if (x2 >= x1) dp[x] = 0;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     for (int i = 1; i <= n; ++i) dp[i] = 0;
//     int pref_zero[200005];

//     for (int d = n; d >= 1; --d) {
//         long long current_total_cost = 0;
//         pref_zero[0] = 0;

//         for (int x = 1; x <= n; ++x) {
//             int cost_x = 1;

//             if (x % d == 0) cost_x = 0;
//             else if (x >= 3) {
//                 for (int x1 = 1; x1 <= x / 3; ++x1) {
//                     if (pref_zero[x1] - pref_zero[x1 - 1] == 1) {
//                         int x3_min = (x - x1 + 1) / 2;
//                         int x3_max = x - 2 * x1;
//                         if (x3_min > x3_max) continue;
//                         if (pref_zero[x3_max] - pref_zero[x3_min - 1] > 0) {
//                             cost_x = 0;
//                             break;
//                         }
//                     }
//                 }
//             }

//             dp[x] = cost_x;
//             pref_zero[x] = pref_zero[x - 1];
//             if (cost_x == 0) pref_zero[x]++;

//             if (a_counts[x] > 0)
//                 current_total_cost += (long long)a_counts[x] * cost_x;
//         }

//         if (current_total_cost <= k) return d;
//     }
//     return 1;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) cout << solve() << "\n";
//     return 0;
// }



#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int count_in_sorted(const std::vector<int>& a, int val) {
    // Find the first element not less than val
    auto lower = std::lower_bound(a.begin(), a.end(), val);
    // If val is not in the array, return 0
    if (lower == a.end() || *lower != val) {
        return 0;
    }
    // Find the first element greater than val
    auto upper = std::upper_bound(a.begin(), a.end(), val);
    // The distance is the count
    return std::distance(lower, upper);
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 1. Sort the array: O(n log n)
    std::sort(a.begin(), a.end());

    // 2. Iterate d from n down to 1: O(n) loop
    for (int d = n; d >= 1; --d) {
        

        auto it = std::lower_bound(a.begin(), a.end(), 4 * d);
        int total_count_less_than_4d = std::distance(a.begin(), it);

        int multiples_count = 0;
        
        // Count d
        multiples_count += count_in_sorted(a, d);
        
        // Count 2*d (only if it's <= n, as all a_i <= n)
        if (2 * d <= n) {
            multiples_count += count_in_sorted(a, 2 * d);
        }
        
        // Count 3*d
        if (3 * d <= n) {
            multiples_count += count_in_sorted(a, 3 * d);
        }
        
        // Cost = (Total < 4d) - (Good multiples < 4d)
        int cost = total_count_less_than_4d - multiples_count;

        // 4. Check if cost is within budget
        if (cost <= k) {
            std::cout << d << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}