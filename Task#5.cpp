#include <iostream>
#include <vector>

using namespace std;
vector<vector<double>> matrix;
vector<vector<double>> b;
vector<vector<double>> res;
int n;

vector<vector<double>> mul(vector<vector<double>> a, vector<vector<double>> b) {
    vector<vector<double>> res(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vector<vector<double >> binaryPow(vector<vector<double> > a, int deg) {
    vector<vector<double>> res(n, vector<double>(n, 0));
    if (deg == 0) {
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    if (deg % 2 == 1) {
        res = binaryPow(a, deg - 1);

        return mul(a, res);
    } else {
        res = binaryPow(a, deg / 2);

        return mul(res, res);
    }

}

int main() {
    freopen("markchain.in", "r", stdin);
    freopen("markchain.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<double> temp;
        vector<double> one;
        double in;
        for (int j = 0; j < n; j++) {
            cin >> in;
            temp.push_back(in);
            one.push_back(1);
        }
        matrix.push_back(temp);
        b.push_back(one);
    }
    res = binaryPow(matrix, 1000000000);
    double sum  = 0;
    for(int i = 0; i < n; i++){
        sum+= res[0][i];
    }
    for(int i = 0; i < n; i++){
        cout << res[0][i]/sum << endl;
    }
    return 0;
}