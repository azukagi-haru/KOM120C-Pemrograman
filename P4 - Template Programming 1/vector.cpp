// membaca dan menghapus bil. bulat dalam posisi tertentu

// read until -9 -> put into vector
// read until -9 -- for each input, treat it as an index to be removed from the vector

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Vektor {
    vector<int> v;
    public:
        vector<int> getVector() { return v; }
        void insert(int i) { v.push_back(i); }
        int len() { return v.size(); }
        void printElements() {
            for (int i=0; i<v.size(); i++) cout << v[i] << " ";
            cout << endl;
        }
        void remove_at_indices(Vektor indices) {
            vector<int> ind = indices.getVector();
            int counter = 0;

            for (int i=0; i<ind.size(); i++) {

                //cout << v[ind[i] - 1 - counter] << " is removed" << endl;
                v.erase(v.begin() + ind[i] - 1 - counter);
                
                counter++;
            }
        }
        double getAverage() {
            if (v.size() == 0) return -9.99;

            int sum = 0;
            for (int i=0; i<v.size(); i++) sum += v[i];
            return (sum*1.0) / v.size();
        }
};

int main() {

    Vektor numbers, indices;

    int num;
    cin >> num;
    while(num != -9) {
        numbers.insert(num);
        cin >> num;
    }
    //numbers.printElements();

    cout << numbers.len() << " ";
    double inital_avg = numbers.getAverage();

    int index;
    cin >> index;
    while(index != -9) {
        indices.insert(index);
        cin >> index;
    }
    //indices.printElements();

    numbers.remove_at_indices(indices);

    cout << setprecision(2) << fixed;
    cout << numbers.len() << endl;
    cout << inital_avg << " " << numbers.getAverage() << endl;

    return 0;
}