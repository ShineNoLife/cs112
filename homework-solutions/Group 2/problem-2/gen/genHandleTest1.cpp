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
    std::cout << "4 3\n1 2 3\n3 2 1\n4 3 1\n";
}
