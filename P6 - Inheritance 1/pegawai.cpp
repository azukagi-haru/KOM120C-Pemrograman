#include <iostream>
#include <vector>
using namespace std;

// base class: Pegawai
class Pegawai {
    protected:
        string id;
        int usia, tipe;
        int income;
    public:
        void set(string pid, int u, int t) { id=pid; usia=u; tipe=t; }
        string getID() { return id; }
        void print() { cout << id << " " << tipe << " " << income << endl; }
};

// class Tetap -> ada "lembur", "setLembur()", "getIncome()" dan override fungsi set() dan print() dari Pegawai
class Tetap : public Pegawai {
    private:
        int lembur;
    public:
        Tetap() { id=""; usia=income=lembur=0; tipe=1; }
        void set(string pid, int u, int t, int inc ) { id=pid; usia=u; tipe=t; income=inc; }
        void setLembur(int lem) { lembur = lem; }
        int getIncome() { return income + lembur; }
        void print() { cout << id << " " << tipe << " " << getIncome() << endl; }
};

// class Harian -> ada "setIncome()"
class Harian : public Pegawai {
    public:
        Harian() { id=""; usia=income=0; tipe=2; }
        void setIncome(int inc) { income = inc; }
};

// untuk menyimpan Tetap dan Harian dalam dua vektor berbeda
class DaftarPegawai {
    private:
        vector<pair<string, Tetap>> list_tetap;
        vector<pair<string, Harian>> list_harian;
    public:
        DaftarPegawai() { list_tetap.clear(); list_harian.clear(); }

        // menambahkan pegawai baru ke dalam vektor berdasarkan tipe
        void addTetap(string id, Tetap t) { list_tetap.push_back(make_pair(id, t)); }
        void addHarian(string id, Harian h) { list_harian.push_back(make_pair(id, h)); }

        // meng-update income dari Pegawai berdasarkan kode dan tipenya
        void updatePegawai(string id, int inc) { 
            for (int i=0; i<list_tetap.size(); i++) {
                if (list_tetap[i].first == id) { list_tetap[i].second.setLembur(inc); }
            }
            for (int i=0; i<list_harian.size(); i++) {
                if (list_harian[i].first == id) { list_harian[i].second.setIncome(inc); }
            }
        }

        // print semua anggota dalam kedua vektor
        void printAll() {
            for (int i=0; i<list_tetap.size(); i++) {
                list_tetap[i].second.print();
            }
            for (int i=0; i<list_harian.size(); i++) {
                list_harian[i].second.print();
            }
        }
};

// Main code
int main(void) {
    int n;
    string id; int age, type, income;
    DaftarPegawai daftar;

    // baca entry sebanyak n, masukkan ke DaftarPegawai
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> id >> age >> type;
        if (type == 1) {
            cin >> income;

            Tetap temp;
            temp.set(id, age, type, income);
            daftar.addTetap(id, temp);
        }
        else if (type == 2) {

            Harian temp;
            temp.set(id, age, type);
            daftar.addHarian(id, temp);
        }
    }

    // baca entry hingga "END", update nilai pegawai pada kedua vektor berdasarkan id-nya
    cin >> id;
    while (id != "END") {
        cin >> income;
        daftar.updatePegawai(id, income);
        cin >> id;
    }

    // print semua anggota pada kedua vektor
    daftar.printAll();
    
    return 0;
}


