#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& a);
void solve(vector<int>& a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a;
    input(a);
    solve(a);
    return 0;
}

void input(vector<int>& a) {
    int n;
    cin >> n;

    a.resize(n);
    for(auto& i: a) {
        cin >> i;
    }

    // for(int i: a) {
    //     cout << i << "\n";
    // }

    return;
}

void solve(vector<int>& a) {
    int sereja, dema;
    int serejaPoints = 0;
    int demaPoints = 0;

    for(int i=0, j=a.size()-1; i<=j; ) {

        if(a[i] >= a[j]) {
            serejaPoints += a[i];
            // cout << "adding " << a[i] << " to serejaPoints...\n";

            i += 1;
            if(i > j) {
                break;
            }
        } else {
            serejaPoints += a[j];
            // cout << "adding " << a[j] << " to serejaPoints...\n";
            
            j -= 1;
            if(i > j) {
                break;
            }
        }

        if(a[i] >= a[j]) {
            demaPoints += a[i];
            // cout << "adding " << a[i] << " to demaPoints...\n";

            i += 1;
            if(i > j) {
                break;
            }
        } else {
            demaPoints += a[j];
            // cout << "adding " << a[j] << " to demaPoints...\n";

            j -= 1;
            if(i > j) {
                break;
            }
        }
    }

    cout << serejaPoints << " " << demaPoints << "\n";
    return;
}