#include <bits/stdc++.h>
using namespace std;

int i, n, k, b, l[100001], t, sum, ans = 999999999;

int main() {

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    cin >> n >> k>>b;

    for (i = 0; i < b; i++) {

        cin>>t;

        l[t - 1] = 1;

    }

    for (i = 0; i < k; i++) {

        sum += l[i];

    }

    for (i = 0; i <= n - k; i++) {

        if (sum < ans) {

            ans = sum;

        }

        sum = sum - l[i] + l[i + k];

    }

    cout << ans << endl;

    return 0;

}
