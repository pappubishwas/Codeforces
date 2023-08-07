#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maximizeScores(vector<int>& arr) {
    int n = arr.size();
    vector<int> maxScores(n);

    // Calculate the prefix sum to optimize the process
    vector<int> prefixSum(n + 1);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    for (int K = 1; K <= n; K++) {
        int score = 0;
        for (int i = 0; i < K; i++) {
            score += arr[i];
        }

        for (int i = K; i <= n; i++) {
            // Calculate the score for each K
            maxScores[K - 1] = max(maxScores[K - 1], score);

            // Add the next element and remove the first element from the bucket
            score += arr[i];
            score -= arr[i - K];
        }
    }

    // Sort maxScores in reverse order to get the output in descending order
    sort(maxScores.rbegin(), maxScores.rend());

    return maxScores;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        vector<int> maxScores = maximizeScores(arr);

        for (int score : maxScores) {
            cout << score << " ";
        }
        cout << endl;
    }

    return 0;
}
