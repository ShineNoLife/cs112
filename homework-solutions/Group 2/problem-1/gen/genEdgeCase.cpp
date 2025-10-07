
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

// t = [1, 9]
// constant: [1, 3] [5, 6, 7]
void genEdgeCase(int t) {
    if(t <= 4) {
        n = 1;
        if(t == 1) a[0] = MINA;
        else if(t == 2) a[0] = MAXA;
        else if(t == 3) a[0] = 0; 
        else a[0] = rnd.next(MINA, MAXA);

        print();
        return;
    } else {
        n = 100000;
        // n = MAXN, a[i] = MAX/MIN
    
        for(int i = 0; i < n; ++i) {
            if(t == 5) a[i] = MINA;
            else if(t == 6) a[i] = MAXA;
            else if(t == 7) a[i] = 0;
            else if(t == 8) a[i] = rnd.next(MINA, MAXA);
            else a[i] = (rnd.next(0, 1) ? MAXA : MINA);
        }
    
        print();
    }
    
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int seed = atoi(argv[2]);
    rnd.setSeed(seed);

    genEdgeCase(type);

    return 0;
}
