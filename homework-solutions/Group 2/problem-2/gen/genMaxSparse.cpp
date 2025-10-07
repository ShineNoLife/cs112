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

	int n = N_MAX / 2; // to make chance to have at least one path
	int m = M_MAX;
	std::cout << n << " " << m << "\n";
	
	std::set<std::pair<int, int> > used;
	for (int i = 0; i < m; i++) {
		int a, b;
		a = rnd.next(0, n - 1), b = rnd.next(0, n - 1);
		int c = rnd.next(C_MIN, C_MAX);
        ++a; ++b;
		std::cout << a << " " << b << " " << std::max(c, 1) << "\n";
	}
	return 0;
}