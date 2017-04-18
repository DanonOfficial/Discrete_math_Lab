#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("shooter.in", "r", stdin);
    freopen("shooter.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    double prob, shot, com = 0;
    for (int i = 0; i < n; i++) {
        cin >> prob;
        prob = pow(1.0 - prob, m);
        if (k == i+1) {
            shot = prob;
        }
        com = com + prob;
    }

    cout <<std::setprecision(13) << shot / com << endl;
    return 0;
}