#include "../include/SortAlgorithms.h"

// O(N^2)
void selection_sort(class VisualWindow &window) {

    VisualVector *vector = window.getVisualVector();
    Event e{};
    int length = vector->getLength();
    // Main loop
    for (int i = 0; i < length && window.isOpen(); i++) {
        // Window handler
        while (window.pollEvent(e)) {
            // Window closed
            if (e.type == Event::Closed) {
                window.close();
                exit(0);
            }
        }

        // With two variables (one for the minimum value and one for its index) we managed to halve the
        // number of memory accesses of the algorithm
        int minimum = (*vector)[i];
        int minumum_index = i;
        // Search for the minimum
        for (int j = i + 1; j < length; j++) {
            if ((*vector)[j] < minimum) {
                minimum = (*vector)[j];
                minumum_index = j;
                vector->addArrayAccesses(1);
            }
        }
        // Variable swap
        if (minumum_index != i) {
            swap((*vector)[i], (*vector)[minumum_index]);
            vector->addArrayAccesses(4);
            vector->addSwaps(1);
        }

        // Adding remaining numComparisons and numArrayAccesses
        vector->addComparisons(length - i);
        vector->addArrayAccesses(length - i);

        // Set a status for exchanged boxes
        vector->setStatus(i, CHANGED);
        vector->setStatus(minumum_index, SELECTED);

        // Draw the current frame
        window.drawAndDisplay();
    }
}

// O(N^2)
void bubble_sort(class VisualWindow &window) {

    VisualVector *vector = window.getVisualVector();
    Event e{};
    int length = vector->getLength();
    // Main loop
    for (int i = 0; i < length - 1 && window.isOpen(); i++) {
        // Window handler
        while (window.pollEvent(e)) {
            // Window closed
            if (e.type == Event::Closed) {
                window.close();
                exit(0);
            }
        }

        for (int j = 0; j < length - i - 1; j++) {
            if ((*vector)[j] > (*vector)[j+1]) {
                swap((*vector)[j],(*vector)[j+1]);
                vector->addArrayAccesses(4);
                vector->addSwaps(1);

                // Adding remaining numComparisons and numArrayAccesses
                vector->addComparisons(length - i);
                vector->addArrayAccesses(length - i);

                // Set a status for exchanged boxes
                vector->setStatus(j, CHANGED);
                vector->setStatus(j + 1, SELECTED);

            }

        }

        // Draw the current frame
        window.drawAndDisplay();
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(class VisualWindow &window, VisualVector *vector, int n, int i) {
    Event e{};
    while (window.pollEvent(e)) {
        // Window closed
        if (e.type == Event::Closed) {
            window.close();
            exit(0);
        }
    }

    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && (*vector)[l] > (*vector)[largest])
        largest = l;
        vector->addComparisons(1);

    // If right child is larger than largest so far
    if (r < n && (*vector)[r] > (*vector)[largest])
        largest = r;

    vector->addComparisons(2);
    vector->addArrayAccesses(2);

    // If largest is not root
    if (largest != i) {
        vector->setStatus(i, SELECTED);
        vector->setStatus(largest, CHANGED);

        swap((*vector)[i], (*vector)[largest]);
        vector->addArrayAccesses(4);
        vector->addSwaps(1);

        // Recursively heapify the affected sub-tree
        heapify(window, vector, n, largest);
    }

}

// main function to do heap sort
void heap_sort(class VisualWindow &window) {
    VisualVector *vector = window.getVisualVector();

    int n = vector->getLength();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(window, vector, n, i);

        window.drawAndDisplay();
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        vector->setStatus(0, SELECTED);
        vector->setStatus(i, CHANGED);

        swap((*vector)[0], (*vector)[i]);
        vector->addArrayAccesses(4);
        vector->addSwaps(1);

        // call max heapify on the reduced heap
        heapify(window, vector, i, 0);
        window.drawAndDisplay();
    }

}