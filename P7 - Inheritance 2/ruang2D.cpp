#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

// base class: Ruang 2 dimensi
class Ruang2D {
    protected:
        double sisi1, sisi2, sisi3, sisi4;
    public:
        virtual double luas() = 0;
        virtual double keliling() = 0;
        void set(double s1=0, double s2=0, double s3=0, double s4=0) {
            sisi1=s1; sisi2=s2; sisi3=s3; sisi4=s4;
        };
};

// spesialisasi Ruang2D -> Segiempat 
class Segiempat : public Ruang2D {
    public:
        double luas() { return (sisi1*sisi2); }
        double keliling() { return (sisi1 + sisi2 + sisi3 + sisi4); }
        void set(double s1=0, double s2=0) { sisi1=sisi3=s1; sisi2=sisi4=s2; }
};

// spesialisasi Ruang2D -> Segitiga
class Segitiga : public Ruang2D {
    public:
        double luas() { return ((sisi1*sisi2)/2); }
        double keliling() { return sisi1 + sisi2 + sisi3; }
        void set(double s1=0, double s2=0) { sisi1=s1; sisi2=s2; sisi3=pow((pow(s1*1.0, 2) + pow(s2*1.0, 2)), 0.5); }
};

// fungsi comparator untuk method sortAll() di class DaftarBentuk
// urutkan dari luas terbesar. Jika luas sama, urutkan dari keliling terbesar
template <typename T>
bool compare(T a, T b) {
    if (a.luas() != b.luas()) { return (a.luas() > b.luas()); }
    else { return (a.keliling() > b.keliling()); }
}

// class untuk menampung vector dari Segiempat dan Segitiga
class DaftarBentuk {
    private:
        vector<Segiempat> list_segiempat;
        vector<Segitiga> list_segitiga;
    public:

        // menambahkan segiempat/segitiga ke dalam vector masing-masing
        void addSegiempat(Segiempat s) { list_segiempat.push_back(s); }
        void addSegitiga(Segitiga s) { list_segitiga.push_back(s); }

        // mengurutkan kedua vektor berdasarkan aturan pada fungsi compare()
        void sortAll() {
            sort(list_segiempat.begin(), list_segiempat.end(), compare<Segiempat>);
            sort(list_segitiga.begin(), list_segitiga.end(), compare<Segitiga>);
        }

        // print luas dan keliling segiempat dan segitiga sesuai format
        void printAll() {

            cout << "SEGIEMPAT" << endl;
            cout << setprecision(1) << fixed;
            for (int i=0; i<list_segiempat.size(); i++) {
                cout << list_segiempat[i].luas() << " " << list_segiempat[i].keliling() << endl;
            }

            cout << "SEGITIGA" << endl;
            for (int i=0; i<list_segitiga.size(); i++) {
                cout << list_segitiga[i].luas() << " " << list_segitiga[i].keliling() << endl;
            }

        }
};

// main code
int main(void) {
    DaftarBentuk daftar;
    int m, n;   // jumlah segiempat dan jumlah segitiga
    double x, y;

    cin >> m >> n;

    for (int i=0; i<m; i++) {
        cin >> x >> y;
        Segiempat temp; temp.set(x, y);
        daftar.addSegiempat(temp);
    } 

    for (int i=0; i<n; i++) {
        cin >> x >> y;
        Segitiga temp; temp.set(x, y);
        daftar.addSegitiga(temp);
    }

    daftar.sortAll();
    daftar.printAll();

    return 0;
}