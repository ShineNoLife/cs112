import sys
import bisect
import random
 
input_data = list(map(int, sys.stdin.buffer.read().split()))
it = iter(input_data)
n = next(it)
q = next(it)

a = [0] * (n)
for i in range(n):
    a[i] = next(it)
 
# Build dictionary of positions of each value
pos = {}
for idx, val in enumerate(a):
    if val not in pos:
        pos[val] = []
    pos[val].append(idx + 1)
 
# Number of random tries
K = 15
out_lines = []

for _ in range(q):
    L = next(it)
    R = next(it)
    length = R - L + 1
    need = length // 2
 
    best = -1
    for _ in range(K):
        # Sample a random index in [L, R]
        x = random.randint(L, R)
        v = a[x - 1]

        # Count occurrences of v in [L, R]
        left = bisect.bisect_left(pos[v], L)
        right = bisect.bisect_right(pos[v], R)
        cnt = right - left

        if cnt > need:
            best = v
            break
    out_lines.append(str(best))
sys.stdout.write(" ".join(out_lines))
