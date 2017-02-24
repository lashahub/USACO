#include<bits/stdc++.h>
using namespace std;

int n, ct;
pair <int, int> t[101];

main() {

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    cin>>n;

    for (int i = 0; i < n; i++) {

        cin >> t[i].first >> t[i].second;

    }

    sort(t, t + n);

    ct = t[0].first + t[0].second;

    for (int i = 1; i < n; i++) {

        if (t[i].first <= ct) {

            ct += t[i].second;

        } else {

            ct = t[i].first + t[i].second;

        }

    }

    cout << ct << endl;

    return 0;

}
