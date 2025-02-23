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
    int check = 1;
    int ind1, ind2, ind3;
    double d, dd;
    while (check) {
        check = 0;
        d = 0.0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                if (i == 0 and j == n - 1) break;
                dd = dist(i, i + 1, x, y) + dist(j, (j + 1) % n, x, y) - dist(i, j, x, y) - dist(i + 1, (j + 1) % n, x, y);
                if (dd > d) {
                    d = dd;
                    ind1 = i;
                    ind2 = j;
                    check = 1;
                }
                for (int k = j + 2; k < n; k++) {
                    if (i == 0 and k == n - 1) break;

                    dd = dist(i, i + 1, x, y) + dist(j, j + 1, x, y) + dist(k, (k + 1) % n, x, y) - dist(i, j + 1, x, y) - dist(i + 1, k, x, y) - dist(j, (k + 1) % n, x, y);
                    if (dd > d) {
                        d = dd;
                        ind1 = i;
                        ind2 = j;
                        ind3 = k;
                        check = 2;
                    }

                    dd = dist(i, i + 1, x, y) + dist(j, j + 1, x, y) + dist(k, (k + 1) % n, x, y) - dist(i, k, x, y) - dist(i + 1, j + 1, x, y) - dist(j, (k + 1) % n, x, y);
                    if (dd > d) {
                        d = dd;
                        ind1 = i;
                        ind2 = j;
                        ind3 = k;
                        check = 3;
                    }

                    dd = dist(i, i + 1, x, y) + dist(j, j + 1, x, y) + dist(k, (k + 1) % n, x, y) - dist(i, j, x, y) - dist((k + 1) % n, j + 1, x, y) - dist(k, i + 1, x, y);
                    if (dd > d) {
                        d = dd;
                        ind1 = i;
                        ind2 = j;
                        ind3 = k;
                        check = 4;
                    }

                    dd = dist(i, i + 1, x, y) + dist(j, j + 1, x, y) + dist(k, (k + 1) % n, x, y) - dist(k, j, x, y) - dist((k + 1) % n, i + 1, x, y) - dist(i, j + 1, x, y);
                    if (dd > d) {
                        d = dd;
                        ind1 = i;
                        ind2 = j;
                        ind3 = k;
                        check = 5;
                    }
                }
            }
        }
        if (check == 1) {
            reverse<double>(ind1 + 1, ind2, x);
            reverse<double>(ind1 + 1, ind2, y);
            reverse<int>(ind1 + 1, ind2, numbers);
        }

        if (check == 2) {
            reverse<double>(ind1 + 1, ind2, x);
            reverse<double>(ind2 + 1, ind3, x);
            reverse<double>(ind1 + 1, ind3, x);
            reverse<double>(ind1 + 1, ind2, y);
            reverse<double>(ind2 + 1, ind3, y);
            reverse<double>(ind1 + 1, ind3, y);
            reverse<int>(ind1 + 1, ind2, numbers);
            reverse<int>(ind2 + 1, ind3, numbers);
            reverse<int>(ind1 + 1, ind3, numbers);
        }

        if (check == 3) {
            reverse<double>(ind1 + 1, ind2, x);
            reverse<double>(ind1 + 1, ind3, x);
            reverse<double>(ind1 + 1, ind2, y);
            reverse<double>(ind1 + 1, ind3, y);
            reverse<int>(ind1 + 1, ind2, numbers);
            reverse<int>(ind1 + 1, ind3, numbers);
        }

        if (check == 4) {
            reverse<double>(ind1 + 1, ind2, x);
            reverse<double>(ind2 + 1, ind3, x);
            reverse<double>(ind1 + 1, ind2, y);
            reverse<double>(ind2 + 1, ind3, y);
            reverse<int>(ind1 + 1, ind2, numbers);
            reverse<int>(ind2 + 1, ind3, numbers);
        }

        if (check == 5) {
            reverse<double>(ind2 + 1, ind3, x);
            reverse<double>(ind1 + 1, ind3, x);
            reverse<double>(ind2 + 1, ind3, y);
            reverse<double>(ind1 + 1, ind3, y);
            reverse<int>(ind2 + 1, ind3, numbers);
            reverse<int>(ind1 + 1, ind3, numbers);
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









