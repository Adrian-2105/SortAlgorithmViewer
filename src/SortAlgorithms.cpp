#include "../include/SortAlgorithms.h"

// Implies 4 memory accesses
void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

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