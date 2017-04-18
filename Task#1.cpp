#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    double result = 0;
    int p, b;
    for (int i = 0; i < k; i++) {
        cin >> p >> b;
        result += p*1.0 / n * (b * 1.0) / 100;
    }
    cout << result << endl;
    return 0;
}