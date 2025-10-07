#include "../testlib.h"
#include "bits/stdc++.h"

const int N_MIN = 2;
const int N_MAX = 100000;
const int M_MIN = 0;
const int M_MAX = 200000;
const int C_MIN = 1;
const int C_MAX = 1e9;


int main(int argc, char **argv) {
	registerGen(argc, argv, 1);
	long long seed = atoll(argv[2]);

    rnd.setSeed(seed);
	seed = atoll(argv[1]);

	int n = N_MAX, m = -1, s = -1, t = -1;
	struct Hen {
		int from;
		int to;
		int cost;
	};
	std::vector<Hen> hens;
	
	if (seed == 0) {
		m = n - 1;
		s = 0;
		t = n - 1;
		
		int k = rnd.next(5, 100);
		for (int i = 1; i < n; i++) {
			if (i < n - k) hens.push_back({0, i, (int) rnd.next(C_MIN, C_MAX)});
			else if (i == n - k) hens.push_back({n - k - 1, i, (int) rnd.next(C_MIN, C_MAX)});
			else {
				int from = rnd.next(n - k, i - 1);
				hens.push_back({from, i, (int) rnd.next(C_MIN, C_MAX)});
			}
		}
	} else if (seed == 1) {
		m = n - 1;
		s = 0;
		t = 2;
		for (int i = 1; i < n; i++) {
			if (i & 1) hens.push_back({0, i, (int) rnd.next(C_MIN, C_MAX)});
			else hens.push_back({i - 1, i, (int) rnd.next(C_MIN, C_MAX)});
		}
	}
	
	auto perm = rnd.perm<int>(n);
	s = perm[s];
	t = perm[t];
	for (auto &i : hens) i.from = perm[i.from], i.to = perm[i.to];
	
	shuffle(hens.begin(), hens.end());
	
    std::cout << n << " " << m << "\n";
    for(auto[from, to, cost] : hens) std::cout << 1+from << " " << 1+to << " " << std::max(1,cost) << "\n";
	return 0;
}