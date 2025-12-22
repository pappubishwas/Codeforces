import sys
input = sys.stdin.readline

INF = 2 * 10**18

class State:
    def __init__(self, score, intervals):
        self.score = score
        self.intervals = intervals  

def merge_intervals(v):
    if not v:
        return v
    v.sort()
    res = [v[0]]
    for l, r in v[1:]:
        if res[-1][1] >= l:
            res[-1] = (res[-1][0], max(res[-1][1], r))
        else:
            res.append((l, r))
    return res

def solve():
    n = int(input())
    x = list(map(int, input().split()))

    cur = [State(0, [(0, INF)])]

    best_hist = -10**9
    buf = -10**9

    for i in range(n - 1):
        d = x[i + 1] - x[i]

        best_hist = max(best_hist, buf)
        buf = -10**9

        candidates = []

        if best_hist >= 0:
            candidates.append((best_hist, (0, d)))

        for st in cur:
            sc = st.score
            for L, R in st.intervals:
                if L < d:
                    buf = max(buf, sc)

                # extend chain
                nl = max(0, d - R)
                nr = min(d, d - L)
                if nl < nr:
                    candidates.append((sc + 1, (nl, nr)))

                # gap = 1
                limit = d - L
                if limit > 0:
                    candidates.append((sc, (0, min(limit, d))))

        cur.clear()
        if not candidates:
            continue

        candidates.sort(reverse=True)  

        i = 0
        while i < len(candidates) and len(cur) < 2:
            sc = candidates[i][0]
            segs = []
            while i < len(candidates) and candidates[i][0] == sc:
                segs.append(candidates[i][1])
                i += 1
            segs = merge_intervals(segs)
            cur.append(State(sc, segs))

    ans = 0
    for st in cur:
        ans = max(ans, st.score)
    ans = max(ans, best_hist, buf)

    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
