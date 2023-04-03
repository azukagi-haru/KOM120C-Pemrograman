#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

class Person {
    private:
        string nama; int usia, tinggi; double berat;
    public:
        // constructor
        Person() {
            nama = ""; usia = 0; tinggi = 0; berat = 0;
        }
        // mutator
        void setPerson(string nam, int u, int t, double b) {
            nama = nam; usia = u; tinggi = t; berat = b;
        }
        // accessor
        string getNama() { return nama; }
        int getUsia() { return usia; }
        int getTinggi() { return tinggi; }
        double getBerat() { return berat; }
        // other member functions
        double getIMT() { return berat/pow(tinggi*0.01, 2); }
        string getStatusGizi() { 
            double imt = getIMT();
            if (imt < 17.0) return "sangat kurus";
            else if (imt >= 17.0 && imt < 18.5) return "kurus";
            else if (imt >= 18.5 && imt < 25.0) return "normal";
            else if (imt >= 25.0 && imt < 28.0) return "gemuk";
            else return "sangat gemuk";
        }
        int getStatusGizi_num() { 
            double imt = getIMT();
            if (imt < 17.0) return 0;
            else if (imt >= 17.0 && imt < 18.5) return 1;
            else if (imt >= 18.5 && imt < 25.0) return 2;
            else if (imt >= 25.0 && imt < 28.0) return 3;
            else return 4;
        }
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

    int statusgizi_list[5] = {0};
    int statusgizi_len = 5;

    cout << setprecision(2) << fixed;
    for (int j=0; j<n; j++) {
        cout << orang[j].getNama() << ' ' << orang[j].getUsia() << ' ' << orang[j].getTinggi() << ' ' << orang[j].getBerat() << ' ' << orang[j].getIMT() << ' ' << orang[j].getStatusGizi() << endl;
        if (orang[j].getTinggi() > tinggi_avg) count++;
        statusgizi_list[orang[j].getStatusGizi_num()]++;
    }

    cout << tinggi_avg << endl;
    cout << count << endl;
    for (int k=0; k<statusgizi_len; k++) {
        cout << statusgizi_list[k];
        if (k == statusgizi_len-1) cout << endl;
        else cout << ' ';
    }

    return 0;
}
