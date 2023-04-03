#include <iostream>
#include <map>
using namespace std;

// class yang merepresentasikan sebuah daftar
// berisi kode akun dan frekuensi transaksinya
class DaftarAkun {
    private:
        map<string, int> transaksi;
    public:
        DaftarAkun() { transaksi.clear(); }
        void set(string kode, int jumlah=0) {
            transaksi[kode]++;
        }
        void print() {
            for (typename map<string, int>::const_iterator it = transaksi.begin(); it != transaksi.end(); ++it) {
                cout << it->first << " " << it->second << endl;
            }
        }
};

int main(void) {
    int t, n;
    string a, b, temp;

    cin >> t;
    for (int i=0; i<t; i++) {
        DaftarAkun daftar;
        cin >> n;

        // supaya string yang terpisah spasi
        // dapat disatukan
        for (int j=0; j<n; j++) {
            cin >> a >> b;
            temp = a + " " + b;
            daftar.set(temp);
        }

        daftar.print();

        // print newline setelah rekap transaksi
        // tapi selain rekap yang terakhir
        if(i == t-1) cout << "";
        else cout << endl;
    }

    return 0;
}