#include <vector>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int> &vector, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && vector[l] > vector[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && vector[r] > vector[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(vector[i], vector[largest]);

        // Recursively heapify the affected sub-tree
        heapify(vector, n, largest);
    }
}

// main function to do heap sort
void heapSort(vector<int> &vector) {
    int n = vector.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vector, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(vector[0], vector[i]);

        // call max heapify on the reduced heap
        heapify(vector, i, 0);
    }
}
