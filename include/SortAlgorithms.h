#ifndef SORT_ALGORITHM_VIEWER_SORTALGORITHMS_H
#define SORT_ALGORITHM_VIEWER_SORTALGORITHMS_H

#include <iostream>
using namespace std;

#include "VisualWindow.h"

// TODO Add new sort methods

void selection_sort(class VisualWindow &window);

void bubble_sort(class VisualWindow &window);

void heap_sort(class VisualWindow &window);

const static map<string, void (*)(class VisualWindow&)> sortAlgorithm = {
        {"selection", selection_sort},
        {"bubble", bubble_sort},
        {"heap", heap_sort}
};

#endif //SORT_ALGORITHM_VIEWER_SORTALGORITHMS_H