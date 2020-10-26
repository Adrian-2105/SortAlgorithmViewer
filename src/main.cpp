#include <cmath>
#include <getopt.h>
#include <iostream>

#include "../include/SortAlgorithms.h"

using namespace std;

void printHelpAndExit(char **argv) {
    cout << "USE: " << argv[0] << " [OPTIONS] <algorithms>\n";
    exit(EXIT_SUCCESS);
}

string charToLowerString(char* s) {
    string out;
    while (*s != '\0') {
        out += *s >= 'A' && *s <= 'Z' ? *s + ('a' - 'A') : *s;
        s++;
    }
    return out;
}


int main(int argc, char *argv[]) {
    // Modifiable parameters
    vector<void (*)(class VisualWindow&)> algorithms;
    int arraySize = DEFAULT_ARRAY_SIZE;
    int framerate = sqrt(arraySize) * 4;
    int windowWidth = DEFAULT_WINDOW_WIDTH;
    int windowHeight = DEFAULT_WINDOW_HEIGHT;

    /*** Argument handler ***/
    {
        struct option long_options[] = {
                {"size",      required_argument, nullptr, 'n'},
                {"framerate", required_argument, nullptr, 'f'},
                {"help",      no_argument,       nullptr, 'h'},
                {nullptr, 0, nullptr, 0}
        };

        char c;
        while ((c = getopt_long(argc, argv, "n:f:W:H:h", long_options, nullptr)) != -1) {
            switch (c) {
                case 'n':
                    arraySize = atoi(optarg);
                    break;
                case 'f':
                    framerate = atoi(optarg);
                    break;
                case 'h':
                default:
                    printHelpAndExit(argv);
            }
        }

        // Read the list of algorithms
        for (int i = optind; i < argc; i++) {
            // Checks if the algorithm is implemented
            auto it = sortAlgorithm.find(charToLowerString(argv[i]));
            if (it != sortAlgorithm.end())
                algorithms.push_back(it->second);
            else {
                cerr << "Error: algorithm " << argv[i] << " is not recognized\n";
                exit(EXIT_FAILURE);
            }
        }

        // Argument validation
        if (algorithms.empty())
            printHelpAndExit(argv);
    }

    /*** Program starts ***/

    /* TODO
     * At the moment, only the first window will be launched.
     * It will be expanded in the future to be able to launch multiple windows
    */

    // Creating and initializing vector
    auto *vector = new VisualVector(arraySize);
    vector->fillWithRandom();
    // Creating and initializing window
    auto *window = new VisualWindow(vector, string(argv[optind]), framerate, windowWidth, windowHeight, "Sort Algorithm Viewer");

    // Infinite iterate loop as long as the window does not close
    Event event{};
    bool exit = false;
    while (window->isOpen()) {
        // Event handling
        while (window->pollEvent(event)) {
            // Window closed
            if (event.type == Event::Closed) {
                window->close();
                exit = true;
            }
        }
        if (exit)
            break;

        // Apply the visual sort algorithm
        algorithms[0](*window);

        // Reinitialize the array
        vector->initialize();
        vector->fillWithRandom();
    }

    delete window;
    delete vector;

    return EXIT_SUCCESS;
}
