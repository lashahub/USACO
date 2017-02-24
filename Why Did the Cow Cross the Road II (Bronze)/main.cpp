#include<bits/stdc++.h>
using namespace std;

int ans;
string str;
pair <int, int> p[27];

int main() {

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    cin>>str;

    for (int i = 0; i < 27; i++) {

        p[i].first = -1;

        p[i].second = -1;

    }

    for (int i = 0; i < 52; i++) {

        if (p[str[i] - 64].first == -1) {

            p[str[i] - 64].first = i + 1;

            continue;

        }

        if (p[str[i] - 64].second == -1) {

            p[str[i] - 64].second = i + 1;

            continue;

        }

    }

    for (int i = 1; i < 27; i++) {

        for (int j = 1; j < 27; j++) {

            if (i == j)continue;

            if (p[j].first > p[i].first && p[j].first < p[i].second && p[j].second > p[i].second) {

                ans++;

            }

        }

    }


    cout << ans << endl;

    return 0;

}
