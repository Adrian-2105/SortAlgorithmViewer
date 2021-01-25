#include "../include/VisualVector.h"

#include <cstdlib>

#define REP(x, y) for (int (x) = 0; (x) < (y); (x) += 1)

#define MAX_NUM_RAND 100000

// Constructor
VisualVector::VisualVector(int _length) {
    // Time Seed Initialization
    srand(time(nullptr));

    array = new int[_length];
    status = new BoxStatus[_length];
    length = _length;
    max_value = MAX_NUM_RAND;

    initialize();
}

// Destroyer
VisualVector::~VisualVector() {
    delete array;
    delete status;
}

// Operators
int & VisualVector::operator[](int i) {
    return array[i];
}

// Getters
int VisualVector::getLength() const {
    return length;
}

int VisualVector::getMaxValue() const {
    return max_value;
}

BoxStatus VisualVector::getStatus(int index) {
    return status[index];
}

long long VisualVector::getNumComparisons() const {
    return contComparisons;
}

long long VisualVector::getNumArrayAccesses() const {
    return contArrayAccesses;
}

long long VisualVector::getNumSwaps() const {
    return contSwaps;
}

// Setters
void VisualVector::setStatus(int index, BoxStatus _status) {
    status[index] = _status;
}


// Main methods
void VisualVector::initialize() {
    contComparisons = 0;
    contArrayAccesses = 0;
    contSwaps = 0;
    REP(i, length) {
        array[i] = 0;
        status[i] = NONE;
    }
}

void VisualVector::fillWithUniform() {
    REP(i, length)
        array[i] = (i * MAX_NUM_RAND) / length;
    sort(&array[0], &array[length], [](int a, int b){return ((double) rand() / (RAND_MAX)) > 0.5;});
}

void VisualVector::fillWithRandom() {
    REP(i, length)
        array[i] = rand() % MAX_NUM_RAND;
}

void VisualVector::addComparisons(int q) {
    contComparisons += q;
}

void VisualVector::addArrayAccesses(int q) {
    contArrayAccesses += q;
}

void VisualVector::addSwaps(int q) {
    contSwaps += q;
}

void VisualVector::print() {
    REP(i, length)
        cout << array[i] << " ";
    cout << endl;
}
