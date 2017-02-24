#include <bits/stdc++.h>
using namespace std;

bool v[101][101];

int ans, n, k, r, a, b, c, d, nc, g;

short x[101][101] = {

    {5}

};

void BoolFalser(int z);

void NeighborCows(int z, int p, int q);

int main() {

    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    cin >> n >> k>>r;

    //int x[2 * n - 1][2 * n - 1];

    g = 2 * n - 1;

    for (int i = 0; i < g; i++) {

        for (int j = 0; j < g; j++) {

            if (i % 2 == 0 && j % 2 == 0) {

                x[i][j] = 0;

                continue;

            }

            if ((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1)) {

                x[i][j] = 1;

                continue;

            }

            if (i % 2 == 1 && j % 2 == 1) {

                x[i][j] = 3;

                continue;

            }

        }

    }

    for (int i = 0; i < r; i++) {

        cin >> a >> b >> c>>d;

        int rx1, ry1, rx2, ry2;

        rx1 = (a - 1)*2;

        ry1 = (b - 1)*2;

        rx2 = (c - 1)*2;

        ry2 = (d - 1)*2;

        int lx, ly;

        lx = (rx1 + rx2) / 2;
        ly = (ry1 + ry2) / 2;

        x[lx][ly] = 2;

    }

    for (int i = 0; i < k; i++) {

        cin >> a>>b;

        x[(a - 1)*2][(b - 1)*2] = 4;

    }

    for (int i = 0; i < g; i += 2) {

        for (int j = 0; j < g; j += 2) {

            BoolFalser(g);

            if (x[i][j] == 4) {

                NeighborCows(g, i, j);

                int dc = k - nc;

                nc = 0;


                ans = ans + dc;

            }

        }

    }

    ans = ans / 2;

    cout << ans << endl;

    return 0;

}

void BoolFalser(int z) {

    for (int i = 0; i < z; i++) {

        for (int j = 0; j < z; j++) {

            v[i][j] = false;

        }

    }

}

void NeighborCows(int z, int p, int q) {

    if (v[p][q])return;

    if (p < 0 || q < 0 || p >= z || q >= z) return;

    if (x[p][q] == 4) {

        nc++;

    }

    v[p][q] = true;

    if (x[p + 1][q] == 1) {

        NeighborCows(z, p + 2, q);

    }

    if (x[p][q - 1] == 1) {

        NeighborCows(z, p, q - 2);

    }

    if (x[p - 1][q ] == 1) {

        NeighborCows(z, p - 2, q);

    }

    if (x[p ][q + 1] == 1) {

        NeighborCows(z, p, q + 2);

    }

}
