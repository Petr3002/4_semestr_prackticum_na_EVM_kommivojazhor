#include <bits/stdc++.h>

using namespace std;

double dist(int i, int j, double* x, double* y) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

template<class T>
void swap(int i, int j, T* a) {
    T tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

template<class T>
void reverse(int i, int j, T* a) {
    for (int k = i; k < (i + j + 1) / 2; k++) {
        swap(k, j + i - k, a);
    }
}

int main() {
    string s;
    cin >> s;
    ifstream in;
    in.open(s);
    int n;
    in >> n;
    double x[n], y[n];
    int numbers[n];
    for (int i = 0; i < n; i++) {
        in >> x[i] >> y[i];
        numbers[i] = i;
    }
    bool check = true;
    int ind1, ind2;
    double d, dd;
    while (check) {
        check = false;
        d = 0.0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                if (i == 0 and j == n - 1) break;
                dd = dist(i, i + 1, x, y) + dist(j, (j + 1) % n, x, y) - dist(i, j, x, y) - dist(i + 1, (j + 1) % n, x, y);
                if (dd > d) {
                    d = dd;
                    ind1 = i;
                    ind2 = j;
                    check = true;
                }
            }
        }
        if (check) {
            reverse<double>(ind1 + 1, ind2, x);
            reverse<double>(ind1 + 1, ind2, y);
            reverse<int>(ind1 + 1, ind2, numbers);
        }
    }
    double length = 0.0;
    for (int i = 0; i < n; i++) {
        length += dist(i, (i + 1) % n, x, y);
    }
    cout << length << ' ' << 1 << endl;
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << ' ';
    }
    return 0;
}









