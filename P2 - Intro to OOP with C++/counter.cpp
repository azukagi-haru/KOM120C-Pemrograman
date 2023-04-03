#include <iostream>
using namespace std;

class Counter {
    int num;
    public:
        Counter() { num=0; }
        void set(int p) { if (p < 0) num = 0; else num=p; }
        void increment() { num++; }
        void decrement() { if (num-1 < 0) num = 0; else num--; }
        void show() { cout << num << endl; }
};

int main() {
    int opr, n;
    Counter counter1;
    cin >> opr;
    while (opr != -9) {
        switch(opr) {
            case 0: cin >> n; counter1.set(n); break;
            case 1: counter1.increment(); break;
            case -1: counter1.decrement(); break;
            case 9: counter1.show(); break;
        }
        cin >> opr;
    }
    return 0;
}