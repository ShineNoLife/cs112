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

	int n = N_MAX;
	int m = M_MAX;
    int s = 1, t = n;
    std::cout << n << " " << m << "\n";
	
	for (int i = 0; i < m; i++) {
		int a, b;
		a = rnd.next(1, n), b = rnd.next(1, n);
		int c = rnd.next((int) C_MIN, C_MAX);
        std::cout << a << " " << b << " " << c << "\n";
	}
	return 0;
}