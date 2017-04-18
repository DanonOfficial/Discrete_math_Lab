#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int p1, p2;
    cin >> p1 >> p2;
    double res = n;
    double pw = 1.0 / p1;
    int a, b;
    for (int i = 0; i < m-1; i++) {
        cin >> a >> b;
        res = res - pw * (a - 1) / a * p2;
        pw = pw * 1.0 / a;
        p2 = b;
    }
    res = res - pw * p2;
    cout <<setprecision(15) << res << endl;
    return 0;
}