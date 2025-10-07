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

// t = [1, 4]
void genSpecialCase(int t) {
    n = rnd.next(10, 100);
    for(int i = 0; i < n; ++i) {
        if(t == 1) {
            a[i] = 0;
        } else if(t == 2) {
            a[i] = rnd.next(1, MAXA);
        } else if(t == 3) {
            a[i] = rnd.next(MINA, -1);
        } else {
            a[i] = (i & 1 ? rnd.next(1, MAXA) : rnd.next(MINA, -1));
        }
    }
    print();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int seed = atoi(argv[2]);
    rnd.setSeed(seed);
    genSpecialCase(type);
    return 0;
}
