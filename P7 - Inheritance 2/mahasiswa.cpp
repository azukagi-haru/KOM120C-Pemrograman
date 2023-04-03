#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

// base class Orang
class Orang {
    protected:
        string nama;
        int usia;
    public:
        Orang() {nama=""; usia=0;}
        void setData(string name, int age) {nama=name; usia=age;}
};

// Mahasiswa diturunkan dari Orang
class Mahasiswa : public Orang {
    protected:
        string nim;
    public:
        Mahasiswa() {nama=""; usia=0; nim="";}
        void setData(string name, int age, string id) {nama=name; usia=age; nim=id;}
};

// Nilai diturunkan dari Mahasiswa
class Nilai : public Mahasiswa {
    protected:
        int sks;    // sks total
        double nilai_total; // (nilai mutu * sks mata kuliah) --> untuk menentukan ipk
    public:
        Nilai() {nama=""; usia=0; nim=""; sks=0; nilai_total=0;}
        void addNilai(int credits, double grading) {sks += credits; nilai_total += grading*credits;}
        double getIpk() { return nilai_total/sks; }
        void printNilai() {
            cout << setprecision(2) << fixed;
            cout << nama << " (" << nim << "):" << sks << ":" << getIpk() << endl;
        }
};

int main(void) {
    string name, id, course, index;
    int age, credits;
    double grading;

    // dictionary untuk mengubah huruf mutu menjadi nilai mutu
    map<string, int>huruf_mutu;
    huruf_mutu["A"] = 4;
    huruf_mutu["B"] = 3;
    huruf_mutu["C"] = 2;
    huruf_mutu["D"] = 1;
    huruf_mutu["F"] = 0;

    // membuat instance dari Nilai
    cin >> name >> age >> id;
    Nilai grade; grade.setData(name, age, id);

    // di praktikum, ini harusnya read until EOF
    int i=0;
    while (i<4) {
        cin >> course >> credits >> index;
        grading = huruf_mutu[index];
        grade.addNilai(credits, grading);
        i++;
    }

    /*
    cin >> course;
    while (course != null) {
        cin >> credits >> index;
        grading = huruf_mutu[index];
        grade.addNilai(credits, grading);
        cin >> course;
    }
    */

    grade.printNilai();

    return 0;
}