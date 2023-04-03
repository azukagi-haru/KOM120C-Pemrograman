#include <iostream>
#include <set>
using namespace std;

typedef pair<int,int> pasangan;

// compare function untuk mengurutkan titik-titik koordinat pada set 
// dari ujung kanan atas hingga ke ujung kiri bawah
struct compare {
    bool operator()(const pasangan& a, const pasangan& b) const {
        if ( (a.first > b.first) || ((a.first == b.first) && (a.second > b.second)) ) return true;
        else return false;
    }
};

class Hotspot {
    set<pasangan, compare> titik;
    public:
        Hotspot() { titik.clear(); }

        int getTotalKoords() {
            return titik.size(); 
        }

        void addKoord(int x, int y) { 
            pasangan tmp = make_pair(x,y);
            titik.insert(tmp);
        }
        
        // print koordinat yang berada pada kuadran 1 atau 2
        // yaitu ketika y_titik > 0
        void printEligibleKoord() {
            set<pasangan, compare>::iterator p;
            for(p=titik.begin(); p!=titik.end(); ++p){
                if (p->second > 0) cout << "(" << p->first << "," << p->second << ")";
            }
            cout << endl;
        }
};

int main() {
    Hotspot koordinat;
    int n, x, y;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        koordinat.addKoord(x,y);
    }

    cout << koordinat.getTotalKoords() << endl;
    koordinat.printEligibleKoord();

    return 0;
}