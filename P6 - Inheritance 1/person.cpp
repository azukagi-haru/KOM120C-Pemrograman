#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Person {
    protected:
        string nama; 	// nama
        char jk; 		// jenis kelamin
        int usia; 		// usia (tahun)
        string kota; 	// kota lahir
    public:
        void set(string n, char j, int u, string k) { nama=n; jk=j; usia=u; kota=k; }
        string getNama() { return nama; }
        char getSex() { return jk; }
        int getUsia() { return usia; }
        string getKota() { return kota; }
};

// spesialisasi untuk laki-laki
class Male : public Person {
    // untuk jk == L
};

// spesialisasi untuk perempuan
class Female : public Person {
    // untuk jk == P
};

// menggunakan template T supaya bisa digunakan Male dan Female
// rata-rata usia
template <class T>
double rataan(vector<T> p) {
	int sum = 0;
	for (int i=0; i<p.size(); i++) {
        sum += p[i].getUsia();
    }
    return (sum*1.0 / p.size());
}

// jumlah orang yang usianya dibawah rata-rata
template <class T>
int under(vector<T> p) {
	double avg = rataan(p);
	int count = 0;
	for (int i=0; i<p.size(); i++) {
        if (p[i].getUsia() < avg) { count++; }
    }
    return count;
}

// Main code
int main(void) {
	vector<Male> L;
	vector<Female> P;
	string line;
    string name; char sex; int age; string city;

    // baca input per line sampai EOF
    // karakter 1-25     -> nama
    // karakter 26       -> jk
    // karakter 27-28    -> usia
    // karakter 29-53    -> kota
    while (getline(cin, line)) {
        name = line.substr(0, 25);
        sex = line[25];
        age = stoi(line.substr(26, 2));
        city = line.substr(28, 25);

        if (sex == 'L') {
            Male temp;
            temp.set(name, sex, age, city); 
            L.push_back(temp); 
        }
        else if (sex == 'P') {
            Female temp;
            temp.set(name, sex, age, city); 
            P.push_back(temp); 
        }
    } 
	
    // print output
    cout << setprecision(2) << fixed;
	cout << "L " << L.size() << " " << rataan(L) << " " << under(L) << endl;
	cout << "P " << P.size() << " " << rataan(P) << " " << under(P) << endl;

	return 0;
}