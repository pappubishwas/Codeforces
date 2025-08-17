#include<bits/stdc++.h>
using namespace std;
int findAnswer(vector<int> &a, int &n) {
    int answer = 1e9;
    for(int i = 0; i < n; i++) {
        bool up = false, down = false;
        for(int j = i + 1; j < n; j++) {
            if(abs(a[i] - a[j]) <= 1) {
                answer = min(answer, j - i - 1);
                break;
            }
            if(a[j] > a[i]) {
                up = true;
            }
            if(a[j] < a[i]) {
                down = true;
            }
            if(up and down) {
                answer = min(answer, j - i - 1);
                break;
            }
        }
    }
    return answer;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int answer1 = findAnswer(a, n);
        reverse(a.begin(), a.end());
        int answer2 = findAnswer(a, n);
        int answer = min(answer1, answer2);
        cout << (answer == 1e9 ? -1 : answer) << "\n";
    }
    return 0;
}