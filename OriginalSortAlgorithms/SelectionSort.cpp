#include <vector>

using namespace std;

// O(N^2)
void selection_sort(vector<int> &vector) {
    int length = vector.size();
    // Main loop
    for (int i = 0; i < length; i++) {
        // With two variables (one for the minimum value and one for its index) we managed to halve the
        // number of memory accesses of the algorithm
        int minimum = vector[i];
        int minumum_index = i;
        // Search for the minimum
        for (int j = i + 1; j < length; j++) {
            if (vector[j] < minimum) {
                minimum = vector[j];
                minumum_index = j;
            }
        }
        // Variable swap
        if (minumum_index != i) {
            int aux = vector[i];
            vector[i] = vector[minumum_index];
            vector[minumum_index] = aux;
        }
    }
}
