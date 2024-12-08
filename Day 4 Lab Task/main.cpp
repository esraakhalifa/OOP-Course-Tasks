#include <iostream>
//#include <graphics.h>
using namespace std;

void line(int x1, int y1, int x2, int y2) {
    cout << "Drawing line from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
}

void rectangle(int x1, int y1, int x2, int y2) {
    cout << "Drawing rectangle from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
}

void circle(int x, int y, int radius) {
    cout << "Drawing circle at (" << x << "," << y << ") with radius " << radius << endl;
}

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Shape
{
private:
    int Color;
public:
    Shape() : Color(0) {}

    Shape(int color): Color(color) {}
    int getColor()
    {
        return Color;
    }
    void setColor(int color)
    {
        this->Color = color;
    }
    virtual void draw() = 0;
};
class Line : public Shape{
private:
    Point start;
    Point end;
public:
    Line() : Shape(), start(), end() {}
    Line(int color,int x1, int y1, int x2, int y2) : Shape(color), start(x1, y1), end(x2, y2) {}

    void draw() {
        // Placeholder for drawing a line
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape{
private:
    Point ul; // Upper-left point
    Point lr; // Lower-right point
public:
    Rect() : Shape(),ul(), lr() {}
    Rect(int color,int x1, int y1, int x2, int y2) : Shape(color), ul(x1, y1), lr(x2, y2) {}

    void draw() {
        // Placeholder for drawing a rectangle
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle : public Shape{
private:
    Point center;
    int radius;
public:
    Circle() : Shape(), center(), radius(0) {}
    Circle(int color,int m, int n, int r) : Shape(color), center(m, n), radius(r) {}

    void draw() {
        // Placeholder for drawing a circle
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture {
private:
    int numOfShapes;
    Shape **shapes;

public:
    Picture() : numOfShapes(0), shapes(nullptr) {}





    void setShapes(int numOfShapes, Shape** shapes) {
        this->numOfShapes = numOfShapes;
        this->shapes = new Shape*[numOfShapes];

        for (int i = 0; i < numOfShapes; ++i) {
            this->shapes[i] = shapes[i];
        }
    }
    ~Picture()
    {
        for (int i = 0; i < numOfShapes; ++i) {
            delete shapes[i];
    }
        delete [] shapes;
    }

    void paint() {
        for (int i = 0; i < numOfShapes; i++)
        {
            shapes[i]->draw();
        }
    }
};



int main() {
    Picture picture;
    Line l(1,1,2,3,4);
    Circle c(1,1,2,5);
    Rect r(1,5,5,2,2);
    Shape* lShape = &l;
    Shape* cShape = &c;
    Shape* rShape = &r;
    Shape* shapesArray[3] = {lShape, cShape, rShape};
    picture.setShapes(3, shapesArray);

    picture.paint();

    return 0;

    return 0;
}
