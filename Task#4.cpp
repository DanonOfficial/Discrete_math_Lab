#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
double Q[400][400];
double R[400][400];
double G[400][400];
double N[400][400];
double E[400][400];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("absmarkchain.in", "r", stdin);
    freopen("absmarkchain.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    pair<int, int> *input = new pair<int, int>[m];
    double *p = new double[m];
    bool *acc = new bool[m];
    double pt;
    int abs = 0;
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            R[i][j] = G[i][j] = N[i][j] = E[i][j] = Q[i][j] = 0;
        }
    }*/
    for(int i = 0; i < m; i++){
        acc[i] = false;
    }
    for (int i = 0; i < m; i++) {

        cin >> input[i].first >> input[i].second;
        input[i].first--;
        input[i].second--;
        cin >> pt;
        p[i] = pt;
        if (input[i].first == input[i].second && fabs(pt - 1.0) < 1e-9) {
            acc[input[i].first] = true;
            abs++;
        }
    }
    /*for(int i = 0; i < m; i++){
        cout << acc[i] << " ";
    }
    cout << endl;*/
    int nonAbs = n - abs;
    int *position = new int[n];
    int count_q = 0, count_r = 0;
    for (int i = 0; i < n; i++) {
        if (acc[i]) {
            position[i] = count_r;
            count_r++;
        } else {
            position[i] = count_q;
            count_q++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (acc[input[i].second]) {
            if (!acc[input[i].first]) {
                R[position[input[i].first]][position[input[i].second]] = p[i];
            }
        } else {
            Q[position[input[i].first]][position[input[i].second]] = p[i];
        }
    }
    for (int i = 0; i < nonAbs; i++) {
        N[i][i] = 1.0;
        E[i][i] = 1.0;
        for (int j = 0; j < nonAbs; j++) {
            E[i][j] -= Q[i][j];
        }
    }
    //cout <<"Ke" <<endl;
    for (int i = 0; i < nonAbs; i++) {
        if ((fabs(E[i][i] - 1.0) > 1e-9)) {
            double mul = E[i][i];
            for (int j = 0; j < nonAbs; j++) {
                E[i][j] /= mul;
                N[i][j] /= mul;
            }
        }
        for (int row = 0; row < nonAbs; row++) {
            if (i != row) {
                double mul = E[row][i];
                for (int j = 0; j < nonAbs; j++) {
                    E[row][j] -= mul * E[i][j];
                    N[row][j] -= mul * N[i][j];
                }
            }
        }

    }
    for(int i = 0; i < nonAbs; i++){
        for(int j = 0; j < abs; j++){
            G[i][j] = 0.0;
            for(int k = 0; k < nonAbs; k++){
                G[i][j] += N[i][k] * R[k][j];
            }
        }
    }
    double prob = 0;
    for(int i = 0; i < n; i++){
        prob = 0;
        if(acc[i]){
            for(int k = 0; k < nonAbs; k++){
                prob += G[k][position[i]];
            }
            prob+=1;
            prob/=n;
        }
        cout << prob << endl;
    }
    return 0;
}
