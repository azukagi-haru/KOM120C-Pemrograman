#include <iostream>
using namespace std;

// class yang merepresentasikan pecahan 
// dalam bentuk a + (b/c)
class Pecahan {
    private:
        int a,b,c;

        // mencari gcd/fpb dari 2 bilangan
        int gcd(int x, int y) {
            if (y == 0) { return x; }
            else { return gcd(y, x%y); }
        }

        // menyederhanakan sebuah pecahan
        void simplify() {
            int fac;
            a = a + b/c;
            b = b%c;
            fac = gcd(b, c);
            b = b/fac;
            c = c/fac;
        }

    public:
        Pecahan() { a=b=0; c=1; }

        void set(int x, int y, int z) { 
            a=x; b=y; c=z;
            simplify();
        }

        Pecahan operator+ (Pecahan const &p) {
            Pecahan result;
            result.a = a + p.a;
            result.b = b*p.c + p.b*c;
            result.c = c*p.c;
            result.simplify();
            return result;
        }

        Pecahan operator* (Pecahan const &p) {
            Pecahan result;
            result.a = 0;
            result.b = ((a*c) + b) * ((p.a*p.c) + p.b);
            result.c = c * p.c;
            result.simplify();
            return result;
        }

        Pecahan operator++ (int) {
            Pecahan result(*this);
            a++;
            return result;
        }

        Pecahan operator-- (int) {
            Pecahan result(*this);
            a--;
            return result;
        }

        void print() {
            if (b == 0) { cout << a << endl; }
            else if (a == 0) { cout << b << "/" << c << endl; }
            else { cout << a << " " << b << "/" << c << endl; }
        }
};

int main(void) {
    Pecahan frac;

    string input;
    int a,b,c;
    while(true) {
        cin >> input;
        if (input == "set") {
            cin >> a >> b >> c;
            frac.set(a,b,c);
        }
        else if (input == "p") { frac.print(); }
        else if (input == "add") {
            cin >> a >> b >> c;
            Pecahan temp; temp.set(a,b,c);
            frac = frac + temp;
        }
        else if (input == "mul") {
            cin >> a >> b >> c;
            Pecahan temp; temp.set(a,b,c);
            frac = frac * temp;
        }
        else if (input == "inc") { frac++; }
        else if (input == "dec") { frac--; }
        else { break; }
    }

    return 0;
}