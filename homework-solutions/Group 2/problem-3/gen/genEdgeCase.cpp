#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

void genEdgeCase1() {
    // n = 1, m = 0
    cout << 1 << " " << 0 << "\n";
}

void genEdgeCase2() {
    // n = 2, m = 0 (không có đường Hamilton)
    cout << 2 << " " << 0 << "\n";
}

void genEdgeCase3() {
    // n = 2, m = 1 (có đường Hamilton)
    cout << 2 << " " << 1 << "\n1 2\n";
}

void genEdgeCase4() {
    // n = 12, m = đầy đủ (complete graph)
    int n = 12;
    cout << n << " " << n*(n-1)/2 << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            cout << i << " " << j << "\n";
}

void genEdgeCase5() {
    // n = 12, m = 0 (đồ thị rỗng)
    cout << 12 << " " << 0 << "\n";
}

void genEdgeCase(int type) {
    if (type == 1) genEdgeCase1();
    else if (type == 2) genEdgeCase2();
    else if (type == 3) genEdgeCase3();
    else if (type == 4) genEdgeCase4();
    else genEdgeCase5();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int seed = atoi(argv[2]);
    rnd.setSeed(seed);
    genEdgeCase(type);
}
