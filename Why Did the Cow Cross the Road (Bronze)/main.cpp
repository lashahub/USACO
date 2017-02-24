#include<bits/stdc++.h>
using namespace std;

int n, ans, x[11], a, b;

int main() {

    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);

    cin>>n;

    for (int i = 0; i < 11; i++) {

        x[i] = -1;

    }

    for (int i = 0; i < n; i++) {

        cin >> a>>b;

        if (x[a] == -1) {

            x[a] = b;

        }
        if (x[a] == 0 && b == 1) {

            ans++;

            x[a] = 1;

        }

        if (x[a] == 1 && b == 0) {

            ans++;

            x[a] = 0;

        }

    }

    cout << ans << endl;

    return 0;

}
