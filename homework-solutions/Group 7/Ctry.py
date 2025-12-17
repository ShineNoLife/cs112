import sys
import heapq

input = sys.stdin.readline
INF = 10**30

def solve():
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        c = [0] + list(map(int, input().split()))

        a = [[0]*(m+1)]
        for _ in range(n):
            row = [0] + list(map(int, input().split()))
            a.append(row)

        # cost(u->v) theo ý tưởng của bạn
        def edge_cost(u, v):
            best = INF
            for x in range(1, m+1):
                need = a[u][x] - a[v][x]
                if need > 0:
                    best = min(best, need)
                else:
                    best = 0
                    break
            return best + c[v]

        # Dijkstra trên n node
        dist = [INF] * (n+1)
        dist[1] = 0
        pq = [(0, 1)]

        while pq:
            d, u = heapq.heappop(pq)
            if d != dist[u]:
                continue
            if u == n:
                break
            for v in range(1, n+1):
                if v == u:
                    continue
                nd = d + edge_cost(u, v)
                if nd < dist[v]:
                    dist[v] = nd
                    heapq.heappush(pq, (nd, v))

        print(dist[n])

solve()
