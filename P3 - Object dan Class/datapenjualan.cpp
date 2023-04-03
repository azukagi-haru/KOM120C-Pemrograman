// goal: pencatatan jumlah barang dan harga
// class yang dibutuhkan -> Barang, DaftarKode, Penjualan

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// class yang merepresentasikan sebuah barang
class Barang {
    public:
        string kode;
        string nama;
        int harga;
};

// class yang merepresentikan sebuah daftar
// yang terdiri dari kode dan objek barang
// yang dapat diisi dan dicari berdasarkan kode
class DaftarKode {
    private:
        map<string,Barang> itemlist;
        int list_size;

    public:
        // constructor
        DaftarKode() { itemlist.clear(); list_size=0; }

        // menginisiasi daftar dengan mengambil input dari stdin
        void init() {
            cin >> list_size;
            Barang temp;
            for(int i=0; i<list_size; i++) {
                cin >> temp.kode >> temp.nama >> temp.harga;
                itemlist.insert({temp.kode, temp});
            }
        };

        // mendapatkan nama barang dari kode
        string getNama(string kode) { return itemlist[kode].nama; };

        // mendapatkan harga barang dari kode
        int getHarga(string kode) { return itemlist[kode].harga; }; 
};

// class yang merepresentasikan daftar penjualan
// membuat daftar baru yang berisi kode barang dan jumlah penjualan
// lalu dibandingkan dengan daftar kode sebelumnya 
// untuk mendapat info lebih lanjut (harga, dll) terkait barangnya

class Penjualan {
    private:
        DaftarKode daftar;
        map<string,int> st;

    public:
        Penjualan() { daftar.init(); }

        // menambah data penjualan
        void add(string kode, int jumlah) {
            if(daftar.getNama(kode) != "") {
                st[kode] += jumlah;
            } 
        }

        // mendapatkan total harga penjualan dari suatu barang
        double getTotalHarga(string kode) {
            double harga;
            harga = daftar.getHarga(kode);

            // total harga dinyatakan dalam satuan "juta rupiah"
            return (1.0 * st[kode] * harga)/1000000;
        }

        // mencetak rekapitulasi penjualan
        void printPenjualanRecap() {
            // sort map penjualan
            // pertama-tama, copy key-value dalam map ke dalam vector vec
            // kedua, sort vector tsb. dengan fungsi sort()
            // fungsi sort tsb. menggunakan fungsi lambda untuk membandingkan berdasarkan value map (2nd value dari pair)
            vector<pair<string, int>> vec(st.begin(), st.end());
            sort(vec.begin(), vec.end(), [](const pair<string, int> &a, const pair<string, int> &b) {return a.second > b.second;});

            // print data penjualan
            double sum = 0.00;
            cout << fixed << setprecision(2);
            for (int i=0; i<vec.size(); i++) {
                cout << vec[i].first << " " << daftar.getNama(vec[i].first) << " " << vec[i].second << " " << getTotalHarga(vec[i].first) << endl;
                sum += getTotalHarga(vec[i].first);
            }
            cout << "Total Nilai : " << sum << " juta rupiah" << endl;
        }
};


int main() {
    Penjualan data_penjualan;
    int n;

    cin >> n;
    string kode; int jumlah;
    for(int i=0; i<n; i++) {
        cin >> kode >> jumlah;
        data_penjualan.add(kode, jumlah);
    }

    data_penjualan.printPenjualanRecap();

    return 0;
}