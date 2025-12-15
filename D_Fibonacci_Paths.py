import sys
sys.setrecursionlimit(10**7)

MOD = 998244353
LIM = 10**18

def dp(ei, E, W, G, memo):
    if memo[ei] != -1:
        return memo[ei]

    a = E[ei][0]
    b = E[ei][1]

    x = W[a]
    y = W[b]
    z = x + y

    if z > LIM:
        memo[ei] = 0
        return 0

    s = 0
    for nxt, idx in G[b]:
        if W[nxt] == z:
            s = (s + 1 + dp(idx, E, W, G, memo)) % MOD

    memo[ei] = s
    return s

def solve():
    inp = sys.stdin.readline
    t = int(inp())
    for _ in range(t):
        n, m = map(int, inp().split())
        W = [0] + list(map(int, inp().split()))

        E = []
        G = [[] for _ in range(n + 1)]

        for i in range(m):
            u, v = map(int, inp().split())
            E.append((u, v))
            G[u].append((v, i))

        memo = [-1] * m
        res = m % MOD

        for i in range(m):
            res = (res + dp(i, E, W, G, memo)) % MOD

        print(res)

solve()
