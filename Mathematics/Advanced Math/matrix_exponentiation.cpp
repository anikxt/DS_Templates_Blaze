#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

typedef vector<vector<int>> matrix;

const int matrixmod = 1234567891;

matrix matrixUnit(int n) {
    matrix res(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        res[i][i] = 1;
    }
    return res;
}

matrix matrixAdd(const matrix &a, const matrix &b) {
    int n = a.size();
    int m = a[0].size();
    matrix res(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            res[i][j] = (a[i][j] + b[i][j]) % matrixmod;
        }
    }
    return res;
}

matrix matrixMul(const matrix &a, const matrix &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    matrix res(n, vector<int> (k));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            for (int p = 0; p < n; ++p)
            {
                res[i][j] = (res[i][j] + (long long)a[i][p] * b[p][j]) % matrixmod;
            }
        }
    }
    return res;
}

matrix matrixPow(const matrix &a, int p) {
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

matrix matrixPowSum(const matrix &a, int p) {
    int n = a.size();
    if (p == 0)
        return matrix(n, vector<int>(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}
// create new as matrix a(#of rows,vector<int>(#of cols))

int main() {
    blaze;

    return 0;
}