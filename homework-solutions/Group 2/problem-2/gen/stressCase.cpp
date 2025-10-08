#include "../testlib.h"
#include "bits/stdc++.h"
using namespace std;

const int N_MAX = 100000;
const int M_MAX = 200000;
const int C_MAX = 1000000000;

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
        n = 1000;
        m = rnd.next(n-1, min(n*(n-1), 20000));
    } else {
        if(rnd.next(0, 1)) {
            n = N_MAX;
            m = M_MAX;
        } else {
            n = 3000;
            vector<pair<int,int>> all;
            for(int i=1;i<=n;i++)
                for(int j=i;j<=n && all.size()<M_MAX;j++)
                    all.push_back({i,j});
            m = all.size();
            cout<<n<<" "<<m<<"\n";
            for(auto [u,v]:all)
                cout<<u<<" "<<v<<" "<<rnd.next(C_MAX-100,C_MAX)<<"\n";
            return 0;
        }
    }
    cout << n << " " << m << "\n";

    for (int i = 0; i < m; ++i) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        long long w = rnd.next(C_MAX-10, C_MAX);
        cout << u << " " << v << " " << w << "\n";
    }
}
