#ifndef SORT_ALGORITHM_VIEWER_VISUALWINDOW_H
#define SORT_ALGORITHM_VIEWER_VISUALWINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "VisualVector.h"

using namespace std;
using namespace sf;

// Window default dimensions
#define DEFAULT_WINDOW_WIDTH 600
#define DEFAULT_WINDOW_HEIGHT 600

// Color palette
#define NONE_COLOR Color::White
#define SELECTED_COLOR Color::Blue
#define CHANGED_COLOR Color::Green

class VisualWindow : public RenderWindow {
private:
    // Properties
    class VisualVector *vector;
    double width, height;
    string algorithm;
    Font font;

    // Helper methods to draw frames
    void drawBarChart(double x, double y, double width, double height);

public:
    // Constructor
    VisualWindow(VisualVector *vector, string algorithm, int framerate, int width, int height, const string &name);

    // Destroyer
    ~VisualWindow() override;

    // Getters
    VisualVector *getVisualVector();
    double getWidth() const;
    double getHeight() const;

    // Draw methods
    void drawAndDisplay();
};


#endif //SORT_ALGORITHM_VIEWER_VISUALWINDOW_H
