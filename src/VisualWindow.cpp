#include <utility>


#include "../include/VisualWindow.h"

#define TOP_MARGIN 50
#define CHAR_SIZE 16
#define TOP_TEXT_POSITION 0, 0

#define ASSETS_FONT "./resources/fonts/"
#define JACK_FONT "jack.ttf"

// Constructors

VisualWindow::VisualWindow(VisualVector *v, string _algorithm, int framerate, int w, int h, const string &name)
        : RenderWindow(VideoMode(w, h), name) {
    vector = v;
    algorithm = move(_algorithm);
    // If a default framerate is not specified there will be no limit
    if (framerate > 0)
        setFramerateLimit(framerate);
    width = w;
    height = h;
    if (!font.loadFromFile(ASSETS_FONT JACK_FONT))
        exit(EXIT_FAILURE);
}

// Destroyer
VisualWindow::~VisualWindow() = default;

// Getters
VisualVector *VisualWindow::getVisualVector() {
    return vector;
}

double VisualWindow::getWidth() const {
    return width;
}

double VisualWindow::getHeight() const {
    return height;
}

// Draw methods
void VisualWindow::drawAndDisplay() {
    // Clear the last frame
    clear();

    // Draw the text of the comparisons and array accesses
    Text topText(algorithm + " Sort - Array size: " + to_string(vector->getLength()) + "\n" +
                            to_string(vector->getNumComparisons()) + " comparisons, " +
                            to_string(vector->getNumArrayAccesses()) + " array accesses, " +
                            to_string(vector->getNumSwaps()) + " swaps",
                 font,
                 CHAR_SIZE);
    topText.setPosition(TOP_TEXT_POSITION);
    topText.setFillColor(Color::White);
    draw(topText);

    // Draw the bar chart
    drawBarChart(0, TOP_MARGIN, width, height - TOP_MARGIN);

    // Display the current frame on screen
    display();
}

void VisualWindow::drawBarChart(double x, double y, double w, double h) {
    // Calculate the dimensions of the bars
    double bar_width = w / vector->getLength();
    double bar_height_mult = (double) h / vector->getMaxValue();

    // Auxiliary variable for the generation of the bars
    RectangleShape rs;

    int length = vector->getLength();
    // Bar draw loop
    for (int i = 0; i < length; i++) {
        // Applies the size and places it in the corresponding position
        double bar_height = bar_height_mult * (*vector)[i];
        rs.setSize(Vector2f(bar_width, bar_height));
        rs.setPosition(Vector2f(bar_width * i + x, h - bar_height + y));
        // Applies a color based on its state and resets the status to NONE
        switch (vector->getStatus(i)) {
            case SELECTED:
                rs.setFillColor(SELECTED_COLOR);
                vector->setStatus(i, NONE);
                break;
            case CHANGED:
                rs.setFillColor(CHANGED_COLOR);
                vector->setStatus(i, NONE);
                break;
            default:
                rs.setFillColor(NONE_COLOR);
        }
        // Add the bar to the current frame
        draw(rs);
    }
}

