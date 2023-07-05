#include <iostream>
using namespace std;

int P(int m, int n) {
    if (n == 1 || m == 1) {
        return 1;
    }
    else if (n > m) {
        return P(m, m);
    }
    else if (m == n) {
        return P(m, m - 1) + 1;
    }
    else {
        return P(m, n - 1) + P(m - n, n);
    }
}

int count_partitions(int m) {
    return P(m, m);
}

int main() {
    int m;
    int n;
    cin >> n;
    cin >> m;
    cout << "kolichestvo razbienii chisla " << m << " ravno " << count_partitions(m) << endl;
    return 0;
}
