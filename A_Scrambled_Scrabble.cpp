#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    string s;
    cin >> s;
    int countV = 0;
    int countY = 0;
    int countN = 0;
    int countG = 0;
    int countOtherC = 0;

    for (char c : s)
    {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            countV++;
        else if (c == 'Y')
            countY++;
        else if (c == 'N')
            countN++;
        else if (c == 'G')
            countG++;
        else
            countOtherC++;
    }

    int totalC = countN + countG + countOtherC;
    int maxNG = min(countN, countG);
    int maxLen = 0;

    // Iterate through the number of NG pairs we decide to form
    for (int k = 0; k <= maxNG; k++)
    {
        // For this scenario, we use k NG blocks.
        // Each NG block consumes 1 N and 1 G (2 chars) but provides 1 Consonant SLOT.
        // Effective Consonant Slots = TotalC - 2*k (used) + k (created) = TotalC - k.
        int slotsC = totalC - k;
        
        // We want to maximize S (syllables) such that we can build them.
        // Requirements for S syllables: S vowels, 2*S consonant slots.
        // Resources: countV, slotsC, countY.
        int s_max = 0;

        // Case 1: We use only natural vowels (S <= countV)
        // We need 2*S <= slotsC + countY
        int limit1 = (slotsC + countY) / 2;
        int s1 = min(countV, limit1);
        s_max = max(s_max, s1);

        // Case 2: We need to use Y as vowels (S > countV)
        // Total items needed: 3*S <= countV + slotsC + countY
        // Also bounded by total vowels possible: S <= countV + countY
        int limit2 = (countV + slotsC + countY) / 3;
        int s2 = min(countV + countY, limit2);
        
        // Only consider s2 if it actually utilizes the "Y as vowel" logic 
        // (meaning it pushes beyond countV), though mathematically max(s1, s2) covers it generally.
        if (s2 > countV) {
            s_max = max(s_max, s2);
        }

        if (s_max > 0) {
            // Base length of S syllables is 3*S (C-V-C)
            // Each NG block adds 1 to the length.
            // We can use at most k NG blocks, limited by the 2*S consonant slots available.
            int currentLen = 3 * s_max + min(k, 2 * s_max);
            maxLen = max(maxLen, currentLen);
        }
    }

    cout << maxLen << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}