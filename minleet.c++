#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minCost(string s) {
    int n = s.length();
    int cost1 = 0, cost2 = 0; // Cost for operation 1 and operation 2, respectively

    // Count the number of '0's and '1's
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            count0++;
        else
            count1++;
    }

    int result = min(count0, count1); // Minimum cost if all characters are inverted to '0' or '1'

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cost1 += (i + 1); // Cost of inverting characters from index 0 to i
            count0--;
        } else {
            cost2 += (i + 1); // Cost of inverting characters from index i to n-1
            count1--;
        }

        // Update the result with the minimum cost obtained so far
        result = min(result, cost1 + count1);
        result = min(result, cost2 + count0);
    }

    return result;
}

int main() {
    string s;
    cout << "Enter the binary string: ";
    cin >> s;

    int cost = minCost(s);
    cout << "Minimum cost to make all characters equal: " << cost << endl;

    return 0;
}
