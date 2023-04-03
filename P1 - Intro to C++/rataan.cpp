#include <iostream>
using namespace std;
#include <iomanip>

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0, total = 0;

    cout << setprecision(2) << fixed;
    if (n==0 || k==0) {cout << 0.00 << endl; return 0;}

    for (int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        if (i % k == 0) {sum += tmp; total++;}
    }

    if (total == 0) {cout << 0.00 << endl; return 0;}

    double avg = (double)sum / total;
    cout << avg << endl;

    return 0;
}