#include "../testlib.h"
#include "bits/stdc++.h"
using namespace std;

const int N_MIN = 2;
const int N_MAX = 1000;
const int C_MIN = 1;
const int C_MAX = 100;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    long long seed = atoll(argv[2]);
    int sub = atoll(argv[3]);
    rnd.setSeed(seed);

    int n = -1, m = -1;
    if(sub == 1) {
        n = 10;
        m = 20;
    } else if(sub == 2) {
        n = rnd.next(5, N_MAX);
        m = rnd.next(n-1, min(n*(n-1), 200000));
    } else {
        n = rnd.next(100000-10, 100000);
        m = m = 200000;
    }

    cout << n << " " << m << "\n";

    // thêm cạnh ngẫu nhiên
    for (int i = 1; i <= m; ++i) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        int w = rnd.next(C_MIN, C_MAX);
        cout << u << " " << v << " " << w << "\n";
    }
}
