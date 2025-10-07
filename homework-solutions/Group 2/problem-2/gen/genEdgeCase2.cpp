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
	int n = 2;
    int m = 0;
    
    std::cout << n << ' ' << m << '\n';
	return 0;
}