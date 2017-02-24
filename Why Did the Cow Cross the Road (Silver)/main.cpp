#include <bits/stdc++.h>
using namespace std;

int c, n, t[20001], ans;

struct FTWQ {
    int ts;
    int tf;
    int q;

};

bool FTWQSorter1(FTWQ const& lhs, FTWQ const& rhs) {

    return lhs.ts < rhs.ts;

}

bool FTWQSorter2(FTWQ const& lhs, FTWQ const& rhs) {

    return lhs.q < rhs.q;

}

FTWQ ab[20001];

int main() {

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    for (int i = 0; i < 20001; i++) {

        ab[i].ts = 0;
        ab[i].tf = 0;
        ab[i].q = 0;

    }

    cin >> c>>n;

    for (int i = 0; i < c; i++) {

        cin >> t[i];

    }

    for (int i = 0; i < n; i++) {

        cin >> ab[i].ts >> ab[i].tf;

    }

    sort(t, t + c);
    sort(ab, ab + n, &FTWQSorter1);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < c; j++) {

            if (ab[i].ts <= t[j] && t[j] <= ab[i].tf) {

                ab[i].q++;

            }

        }

    }

    sort(ab, ab + n, &FTWQSorter2);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < c; j++) {

            if (ab[i].ts <= t[j] && t[j] <= ab[i].tf && t[j] != -1) {

                ans++;

                t[j] = -1;

                break;

            }

        }

    }

    cout << ans << endl;

    return 0;

}
