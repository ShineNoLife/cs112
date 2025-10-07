#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int MINA = -100000;
const int MAXA = 100000;

int n, a[100005];

void print() {
    assert(n > 0);

    cout << n << "\n";
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i==n-1];
    }
    
    for(int i = 0; i < n; ++i) a[i] = 0;
    n = 0;
}

void genNormalCase() {
    n = rnd.next(10, 100);
    for(int i = 0; i < n; ++i) {
        a[i] = rnd.next(-100, 100);
    }

    print();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int seed = atoi(argv[2]);
    rnd.setSeed(seed);

    genNormalCase();
    return 0;
}
