#ifndef SORT_ALGORITHM_VIEWER_VISUALVECTOR_H
#define SORT_ALGORITHM_VIEWER_VISUALVECTOR_H

#include <iostream>
#include "SortAlgorithms.h"

using namespace std;

#define DEFAULT_ARRAY_SIZE 100

enum BoxStatus {
    NONE = 0, SELECTED = 1, CHANGED = 2
};

class VisualVector {
private:
    // Properties
    int *array;
    BoxStatus *status;
    int length;
    int max_value;
    // Counters
    long long contComparisons = 0, contArrayAccesses = 0, contSwaps = 0;

public:
    // Constructor
    explicit VisualVector(int length);

    // Destroyer
    ~VisualVector();

    // Operators
    int & operator[](int i);

    // Getters
    int getLength() const;
    int getMaxValue() const;
    BoxStatus getStatus(int index);
    long long getNumComparisons() const;
    long long getNumArrayAccesses() const;
    long long getNumSwaps() const;

    // Setters
    void setStatus(int index, BoxStatus status);

    // Main methods
    void initialize();
    void fillWithUniform();
    void fillWithRandom();
    void addComparisons(int q);
    void addArrayAccesses(int q);
    void addSwaps(int q);
    void print();
};


#endif //SORT_ALGORITHM_VIEWER_VISUALVECTOR_H
