#include <iostream>
using namespace std;

#define ll long long

// Function to calculate GCD using Extended Euclidean Algorithm
ll extendedGCD(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// Function to find modular multiplicative inverse
ll modInverse(ll A, ll M) {
    ll x, y;
    ll gcd = extendedGCD(A, M, x, y);
    if (gcd != 1) {
        // Modular inverse doesn't exist
        return -1;
    } else {
        // Ensuring the result is positive
        return (x % M + M) % M;
    }
}

int main() {
    ll A = 6, M = 1000000007;

    // Function call
    cout <<(3*( modInverse(A, M)))%M;

    return 0;
}
