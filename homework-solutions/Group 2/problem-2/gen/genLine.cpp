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
	int len = std::min(N_MAX - 1, M_MAX);
	int n = len + 1;
	int m = len;
    int s = 1, t = n;
	
	struct Hen {
		int from;
		int to;
		int cost;
	};
	std::vector<Hen> hens;
	for (int i = 0; i < len; i++) hens.push_back({i, i + 1, C_MAX});
	
	auto perm = rnd.perm<int>(n);
	for (auto &i : hens) i.from = perm[i.from], i.to = perm[i.to];
	
	shuffle(hens.begin(), hens.end());
    
    std::cout << n << " " << m << '\n';
    for(auto i : hens) std::cout  << 1+i.from << " " << 1+i.to << " " << i.cost << "\n";
	return 0;
}