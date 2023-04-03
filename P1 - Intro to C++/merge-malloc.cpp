#include <iostream>
using namespace std;
#include <cstdlib>

int main() {
    int a, b;
    int *arr1, *arr2, *arr3;

    cin >> a >> b;

    arr1 = (int*) malloc(sizeof(int)*a);
    arr2 = (int*) malloc(sizeof(int)*b);
    arr3 = (int*) malloc(sizeof(int)*(a+b));

    // fill in the arrays
    for (int m=0; m<a; m++) cin >> arr1[m];
    for (int n=0; n<b; n++) cin >> arr2[n];

    // fill array 3 until one of the array is used up
    int i=0, j=0, k=0;
    while (i<a && j<b) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        }
        else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    // print the rest of the elements for the other array
    while (i<a) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j<b) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    // print array 3
    for (int z=0; z<(a+b); z++) {
        cout << arr3[z];
        if (z == (a+b-1)) cout << endl;
        else cout << ' ';
    }

    return 0;
}