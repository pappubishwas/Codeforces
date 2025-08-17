// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<long long> a(n);
//         for (int i = 0; i < n; ++i) cin >> a[i];

//         sort(a.begin(), a.end()); // it was already sorted.....
//         long long mx = a.back();

//         long long res = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 long long S = a[i] + a[j];
//                 // search only in k >= j+1
//                 auto L = upper_bound(a.begin() + j + 1, a.end(), mx - S); // first > mx - S
//                 auto R = lower_bound(a.begin() + j + 1, a.end(), S);      // first >= S
//                 if (L < R) res += (R - L);
//             }
//         }
//         cout << res << '\n';
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for(int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
//         long long answer = 0;
//         for(int i = 2; i < n; i++) {
//             int bobChoose = max(a[n - 1], 2 * a[i]);
//             for(int j = i - 1; j >= 1; j--) {
//                 int low = 0, high = j - 1, mid, pt = -1;
//                 while(low <= high) {
//                     mid = (low + high) >> 1;
//                     if(a[mid] + a[j] + a[i] > bobChoose) {
//                         pt = mid, high = mid - 1;
//                     } else {
//                         low = mid + 1;
//                     }
//                 }
//                 if(pt != -1) {
//                     answer += j - pt;
//                 }
//             }
//         }
//         cout << answer << "\n";

//     }
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int mx = a[n-1]; 
        long long res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1, r = n - 1, t = -1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a[i] + a[j] + a[m] > mx && a[i] + a[j] > a[m]) {
                        t = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                if (t != -1) res += t - j;
            }
        }
        cout << res << "\n";
    }
    return 0;
}







// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     int mx = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         mx = max(mx, a[i]);
//     }

//     sort(a.begin(), a.end());

//     long long res = 0;

//     // Fix the first two elements a[i] and a[j] in O(N^2)
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
            
//             // Now, find the number of valid k's using binary search in O(log N)
            
//             // 1. Find the lower bound for k: a[k] > mx - a[i] - a[j]
//             // We search in the range from index j+1 to the end.
//             auto it_low = upper_bound(a.begin() + j + 1, a.end(), mx - a[i] - a[j]);

//             // 2. Find the upper bound for k: a[k] < a[i] + a[j]
//             auto it_high = lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]);

//             // The number of valid k's is the distance between these two iterators
//             if (it_high > it_low) {
//                 res += distance(it_low, it_high);
//             }
//         }
//     }
//     cout << res << endl;
// }

// int main() {
//     // Fast I/O
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }