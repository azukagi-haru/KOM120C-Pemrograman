#include <iostream>
using namespace std;
#include <iomanip>

class Person {
    private:
        string nama; int usia, tinggi; double berat;
    public:
        Person() {
            nama = ""; usia = 0; tinggi = 0; berat = 0;
        }
        void setPerson(string nam, int u, int t, double b) {
            nama = nam; usia = u; tinggi = t; berat = b;
        }
        string getNama() { return nama; }
        int getUsia() { return usia; }
        int getTinggi() { return tinggi; }
        double getBerat() { return berat; }
};

int main() {
    int n;    
    cin >> n;

    Person orang[n];

    string inp_nama; int inp_usia, inp_tinggi; double inp_berat;
    double tinggi_total = 0;
    double tinggi_avg;
    int count = 0;

    for (int i=0; i<n; i++) { 
        cin >> inp_nama >> inp_usia >> inp_tinggi >> inp_berat;

        orang[i].setPerson(inp_nama, inp_usia, inp_tinggi, inp_berat);
        tinggi_total += orang[i].getTinggi();
    }
    
    tinggi_avg = 1.0 * tinggi_total / n;

    for (int j=0; j<n; j++) {
        cout << orang[j].getNama() << ' ' << orang[j].getUsia() << endl;
        if (orang[j].getTinggi() > tinggi_avg) count++;
    }

    cout << setprecision(2) << fixed;
    cout << tinggi_avg << endl;
    cout << count << endl;

    return 0;
}
