#include <vector>

using namespace std;

// O(N^2)
void bubble_sort(vector<int> &vector) {
    int length = vector.size();
    // Main loop
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            // Variable swap
            if (vector[j] > vector[j + 1]) {
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}
