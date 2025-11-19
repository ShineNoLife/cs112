# Nhom 3
import sys, time, random

cover = []
def get_cover(n, x, y, R):
    s = set()
    x1, x2 = max(1, x - R), min(n, x + R)
    y1, y2 = max(1, y - R), min(n, y + R)
    for i in range(x1, x2 + 1):
        for j in range(y1, y2 + 1):
            if max(abs(x - i), abs(y - j)) <= R:
                s.add((i, j))
    return s

def greedy_cover(n, sensors, R):
    board = set((i, j) for i in range(1, n + 1) for j in range(1, n + 1))
    cover_sets = []
    for idx, (x, y, c) in enumerate(sensors):
        cover_sets.append(cover[idx])
    
    covered = set()
    selected = []
    total_cost = 0
    while covered != board:
        best = None
        best_ratio = None
        random_pos = random.choice(list(board - covered))
        
        for st, cost, idx in cover_sets:
            if (random_pos not in st):
                continue
            new = len(st - covered)
            if new == 0: 
                continue
            ratio = cost / new

            if best is None or ratio < best_ratio or (abs(ratio-best_ratio) < 1e-12 and cost < best[1]):
                best = (st, cost, idx)
                best_ratio = ratio
        if best is None:
            break
        st, cost, idx = best
        
        selected.append(idx)
        total_cost += cost
        covered |= st
        cover_sets = [(_st, _cost, _idx) for (_st, _cost, _idx) in cover_sets if _idx != idx]
    
    return selected, total_cost

def solve():
    input = sys.stdin.readline
    n, m, R = map(int, input().split())
    sensors = [tuple(map(int, input().split())) for _ in range(m)]  # (x, y, c)

    for idx, (x, y, c) in enumerate(sensors):
        cover.append((get_cover(n, x, y, R), c, idx + 1))   

    time_limit = 2.9
    start_time = time.time()
    best_selected = []
    best_cost = float('inf')
    found = False

    while time.time() - start_time < time_limit:
        selected, total_cost = greedy_cover(n, sensors, R)
        if total_cost < best_cost:
            best_selected = selected[:]
            best_cost = total_cost
            found = True

    selected_sorted = sorted(best_selected)
    if not found:
        print(0)
        print()
        print(-1)
        return

    print(len(selected_sorted))
    for x in selected_sorted:
        x += 1
    
    if selected_sorted:
        print(" ".join(map(str, selected_sorted)))
    else:
        print()
    print(best_cost)

if __name__ == "__main__":
    solve()