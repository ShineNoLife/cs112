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
    int n, m;
    if(seed == 0) {
        n = 20;
        m = n*n;
    } else {
        n = N_MAX;
        m = rnd.next(n-1, M_MAX);
    }
    int s = 1, t = n;
    std::cout << n << " " << m << "\n";
	
	for (int i = 0; i < m; i++) {
		int a, b;
		a = rnd.next(1, n), b = rnd.next(1, n-1);
		int c = rnd.next((int) C_MIN, 100);
		std::cout << a << " " << b << " " << c << '\n';
	}
	return 0;
}